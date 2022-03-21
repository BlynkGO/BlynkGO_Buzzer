/*
 *********************************************************************
 * ลิขลิทธิ์ (License)
 * 
 *   1. โคดไฟล์ BlynkGO_Buzzer.h นี้เป็นไลบรารี่ลิขลิทธิ์ 
 *   สร้างโดย BlynkGO
 *   
 *   2.ไม่อนุญาต แก้ไข โดยไม่ได้รับอนุญาต 
 *   
 *   3.ผู้ใช้สามารถนำไปใช้สร้าง firmware/rom 
 *   สำหรับ บอร์ด ESP32 เพื่อใช้ทางการค้าต่างๆได้
 *   โดยห้ามแจกจ่าย จำหน่าย ดัดแปลง แก้ไขใดๆ ในตัว source ไลบรารี่ออกไป
 *   ให้ทำการลง link ดาวโหลดจาก https://www.github.com/BlynkGO/BlynkGO_Buzzer เท่านั้น
 *
 *   4.หากมีการนำไปใช้คอมไพล์ถือว่าได้ยอมรับ ตามเงื่อนไขลิขสิทธิ์ดังกล่าว
 *   เป็นที่เรียบร้อยแล้ว
 * 
 *********************************************************************
 */

#ifndef __BLYNKGO_BUZZER_H__
#define __BLYNKGO_BUZZER_H__

#define __BLYNKO_BUZZER_VERSION__      "1.0.0"

#include <Arduino.h>
#include <Ticker.h>
#include "melody_struct.h"

class Buzzer {
  public:
    Buzzer(uint8_t pin, uint8_t channel=2)                 {_pin =pin; _channel = channel; ledcSetup(_channel, 12000, 8);}
    ~Buzzer()                                              { ledcDetachPin(_pin); ledcWrite(_channel,0); }
    typedef void(*fn_playback_done)(void);

    void tone(uint16_t freq) {
      noTone();
      if (ledcRead(_channel)) {
        log_e("Tone channel %d is already in use", _channel);
        return;
      }
      _freq =freq;
      ledcAttachPin(_pin, _channel);
      ledcWriteTone(_channel, _freq);
    }
    void noTone(){
      ledcWrite(_channel, 0);
      ledcDetachPin(_pin);
      pinMode(_pin, INPUT);
    }
    
    void setOnce(uint16_t freq, uint32_t duration=500, fn_playback_done fn_done=NULL) {
      static Buzzer* _buz = this;
      _fn_done = fn_done;
      tone(freq);
      _timer.once_ms(duration, [_buz](){
        _buz->noTone();
        if(_buz->_fn_done!=NULL) {
          _buz->_fn_done();
        }
      });
    }

    void setInterval(uint16_t freq, uint32_t duration=500) {
      static bool _tone;
      static Buzzer* _buz = this;
      _freq = freq;
      tone(_freq); _tone = true;
      _timer.attach_ms(duration, [_buz,_tone](){
        (_tone = !_tone)? _buz->tone(_buz->_freq): _buz->noTone();
      });
    }

    void stop(){
      noTone();
      _timer.detach();
      _beep_rewind = false;
    }

    void beep(int8_t cnt=-1,  fn_playback_done fn_done=NULL, uint16_t freq=NOTE_G7, uint32_t duration=200){
      static Buzzer* _buz = this;
      if(cnt == -1 ) _beep_rewind = true;
      _fn_done = fn_done;
      _beep_cnt = cnt;
      _freq = freq;
      _duration = duration;

      tone(_freq);
      _timer.once_ms(duration, [_buz](){
        _buz->noTone();
        _buz->_timer.once_ms( 50, [_buz](){
          if( _buz->_beep_rewind) {
            _buz->beep( -1, _buz->_fn_done, _buz->_freq, _buz->_duration);
          }else{
            if(_buz->_beep_cnt-1 > 0) {
              _buz->beep( _buz->_beep_cnt-1, _buz->_fn_done, _buz->_freq, _buz->_duration);
            }else{
              if(_buz->_fn_done) {
                _buz->_fn_done();
              }
            }
          }
        });
      });
    }
    void addMelody(melody_t &melody){
      stopMelody();
      _melody = &melody;
      float quarter_note_ms = 60000.0/_melody->bpm; 
      _melody_multiply = quarter_note_ms/200.0; 
    }

    void _playMelody(int16_t note_id){
      if(_melody == NULL) return;

      if(note_id >= _melody->size) {
        note_id = 0;
        if(!this->_rewind) { 
          if(_melody_cnt-1 > 0){
            _melody_cnt--;
          }else{
            if(_fn_done) {_fn_done(); }
            return;
          }
        }
      }

      static Buzzer* _buz = this;
      _note_id = note_id;
      if( _melody->notes[_note_id].note == NO_NOTE){
        noTone();
      }else{
        tone( _melody->notes[_note_id].note);
      }

      _buz->_timer.once_ms(_melody->notes[_note_id].duration * _buz->_melody_multiply, [_buz](){
        _buz->noTone();
        _buz->_timer.once_ms(5, [_buz](){
          _buz->_playMelody(_buz->_note_id+1);
        });
      });
    }

    void playMelody(int8_t cnt=-1,  fn_playback_done fn_done=NULL){
      _fn_done = fn_done;
      _rewind = (cnt == -1 );
      _melody_cnt = cnt;
      if(_pause) {
        _pause = false;
        _playMelody(_note_id);
      }else{
        _playMelody(0);
      }
    }

    inline void pauseMelody()   { this->stop(); _pause= true;}
    inline void stopMelody()    { this->stop(); _note_id = 0; _pause=false; _rewind=false; }
    inline void bpm(uint16_t beat)    { float quarter_note_ms = 60000.0/beat; _melody_multiply = quarter_note_ms/200.0; }   // beats per minute of quarter-note ( ค่า beat ต่อ นาที สำหรับ note ตัวดำ)
    inline uint16_t bpm()              { return round(60000.0/ (_melody_multiply*200)); }

    Ticker  _timer;
    uint16_t _freq;
    melody_t *_melody=NULL;
    int16_t  _note_id;
    int8_t  _beep_cnt;
    int8_t  _melody_cnt;
    uint32_t _duration;
    fn_playback_done _fn_done=NULL;
    bool    _beep_rewind=false;
    bool    _rewind=false;
    float   _melody_multiply=1.0;

  private:
    uint8_t _pin;
    uint8_t _channel;
    bool    _pause=false;
    uint8_t _bgo_channel=251;
};


#endif //__BLYNKGO_BUZZER_H__

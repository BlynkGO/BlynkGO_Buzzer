#include <BlynkGOv2.h>
#include <BlynkGO_Buzzer.h>

MELODY_DECLARE(melody_doremi);
MELODY_DECLARE(melody_icecream_walls);

GLabel  label;
GButton btn_melody(SYMBOL_PLAY);
Buzzer  buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();

  BlynkGO.begin();
  BlynkGO.fillScreen(TFT_BLUE, TFT_CYAN);

  buzzer.addMelody(melody_doremi);
  // buzzer.addMelody(melody_icecream_walls));

  btn_melody.size(80,80);
  btn_melody.corner_radius(20);
  btn_melody.color(TFT_GREEN);
  btn_melody.onClicked([](GWidget*widget){
    static bool beep_mode; 
    if(beep_mode = !beep_mode) {
      buzzer.playMelody();  btn_melody = SYMBOL_STOP; btn_melody.color(TFT_RED);
    } else{
      buzzer.pauseMelody(); btn_melody = SYMBOL_PLAY; btn_melody.color(TFT_GREEN);
    }
  });

  label.align(ALIGN_TOP,0,20);
  label.font(prasanmit_25);
  static GTimer timer_lb;
  timer_lb.setInterval(1000, [](){
    static int counter;
    label = "Melody เล่นไป โดยสิ่งอื่นๆก็ยังทำงานต่อไปได้ : " + String(++counter);
  });

}

void loop(){
  BlynkGO.update();
}

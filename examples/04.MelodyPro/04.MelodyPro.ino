/***********************************************
 * ตัวอย่างเล่น โน้ต Melody แบบ None-Blocking 
 * เวลาจะไม่ถูกหยุดค้างด้วย delay(..)
 * อุปกรณ์รอบข้างอื่นๆ ยังทำงานต่อไปได้ระหว่างมีการเล่น melody
 * 
 ***********************************************/

#include <BlynkGO_Buzzer.h>

MELODY_DECLARE(melody_jingle_bells);

Buzzer buzzer(23);              // กำหนดขา pin ของ buzzer

void setup() {
  Serial.begin(115200); Serial.println();

  buzzer.addMelody(melody_jingle_bells);

  buzzer.playMelody();         // play แบบ วนไปเรื่อยๆ

  // หากจะ play แบบรอบเดียว
  // buzzer.playMelody(false);

  // หากจะ play แบบรอบเดียว และ เมื่อเล่นเสร็จให้ทำอะไรต่อ
  // buzzer.playMelody(false, [](){
  //   /* เมื่อเล่นจบให้ทำอะไรวางตรงนี้ */
  //   Serial.println("[Melody] Done");
  // });

  // buzzer.pauseMelody();     // หากจะ pause หยุดชั่วคราว
  // buzzer.playMelody();      // หากจะ กลับมาเล่นต่อจากที่เคย pause ไว้
  // buzzer.stopMelody();      // หากจะ stop ยกเลิกการ play เลย

}

void loop(){

}

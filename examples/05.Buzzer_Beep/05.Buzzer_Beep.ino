#include <BlynkGO_Buzzer.h>

Buzzer buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();
  
  buzzer.beep(3); // beep แบบ 3 รอบ

  // buzzer.beep();  // beep แบบไม่หยุด
  // buzzer.stop();  // หาก beep แบบไม่หยุด แล้วต้องการให้ยกเลิก beep
}

void loop(){
  
}

#include <BlynkGO_Buzzer.h>


Buzzer buzzer(23);                  // กำหนดขา pin

void setup(){
  
  buzzer.setInterval(NOTE_C4,500);  // เล่นโนต C4 (โด) 500ms แล้วหยุด 500ms สลับไปเรื่อยๆ

  // หากจะสั่งหยุด เรียก buzzer.stop();
  
}

void loop(){
  
}
#include <BlynkGO_Buzzer.h>


Buzzer buzzer(23);              // กำหนดขา pin

void setup(){
	Serial.begin(115200); Serial.println();
  
  buzzer.setOnce(NOTE_C4,500);  // เล่นโนต C4 (โด) นาน 500 ms รอบเดียว
  
  // เล่นโนต C4 (โด) นาน 500 ms รอบเดียว
  // และเมื่อเล่นเสร็จ จะให้ไปทำอะไรต่อ
  // buzzer.setOnce(NOTE_C4,500,[](){
  //   /* หากจะให้ไปทำอะไรต่อให้วางตรงนี้ */
  //   Serial.println("[Buzzer] Done");
  // });  
}

void loop(){
  
}

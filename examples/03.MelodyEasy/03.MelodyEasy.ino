/***********************************************
 * ตัวอย่างเล่น โน้ต Melody แบบ อย่างง่าย
 * เวลาหยุดค้างด้วย delay(..)
 * อุปกรณ์รอบข้างอื่นๆ ไม่สามารถทำงานได้ ระหว่างมีการเล่น melody
 * 
 ***********************************************/

#include <BlynkGO_Buzzer.h>

Buzzer buzzer(23);                  // กำหนดขา pin

void setup(){
//  buzzer.tone(NOTE_C4); delay(500); // โด
//  buzzer.tone(NOTE_D4); delay(500); // เร
//  buzzer.tone(NOTE_E4); delay(500); // มี
//  buzzer.tone(NOTE_F4); delay(500); // ฟา
//  buzzer.tone(NOTE_G4); delay(500); // ซอล
//  buzzer.tone(NOTE_A4); delay(500); // ลา
//  buzzer.tone(NOTE_B4); delay(500); // ที
}

void loop(){
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_E4); delay(500);
  buzzer.tone(NOTE_G4); delay(500);
  buzzer.tone(NOTE_C4); delay(500);
  buzzer.tone(NOTE_D4); delay(500);
  buzzer.tone(NOTE_E4); delay(500);
  buzzer.noTone();      delay(500);
  buzzer.noTone();      delay(500);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);

  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_D4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_D4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_D4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_G4); delay(500); buzzer.noTone(); delay(5);

  buzzer.noTone();      delay(500);
  
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_E4); delay(500);
  buzzer.tone(NOTE_G4); delay(500);
  buzzer.tone(NOTE_C4); delay(500);
  buzzer.tone(NOTE_D4); delay(500);
  buzzer.tone(NOTE_E4); delay(500);
  buzzer.noTone();      delay(500);
  buzzer.noTone();      delay(500);
  buzzer.noTone();      delay(500);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);

  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_E4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.tone(NOTE_G4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_G4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_F4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_D4); delay(500); buzzer.noTone(); delay(5);
  buzzer.tone(NOTE_C4); delay(500); buzzer.noTone(); delay(5);
  
  buzzer.noTone();      delay(500);  
}

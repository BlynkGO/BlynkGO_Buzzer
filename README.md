# BlynkGO_Buzzer
 ESP32 Buzzer with beep and melody  by non-blocking  
### คุณสมบัติ
 - เล่น beep ได้
 - เล่น tone ได้
 - เล่น melody ได้
 - ทำงานแบบ non-blocking  
   ทำให้สามารถเล่นเสียงไปได้ พร้อมๆกับ ทำงานอุปกรณ์รอบข้างอื่นๆได้  
   โดยไม่ต้องหยุดรอจนกว่าจะเล่นเสียงเสร็จ 

## Buzzer Wiring

<p align="center">
  <img src="images/BlynkGO_Board_buzzer_wiring.png" alt="image"/>
</p>  
<p align="center">
  <img src="images/ESP32_buzzer_wiring.png" alt="image"/>
</p>  


## Buzzer Beep

```cpp
#include <BlynkGO_Buzzer.h>

Buzzer buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();
  
  buzzer.beep(3);    // beep 3 times

  // buzzer.beep();  // beep non stop
  // buzzer.stop();  // stop beeping
}

void loop(){
  
}
```

## Buzzer Melody

```cpp

#include <BlynkGO_Buzzer.h>

MELODY_DECLARE(melody_jingle_bells);

Buzzer buzzer(23);              // กำหนดขา pin ของ buzzer

void setup() {
  Serial.begin(115200); Serial.println();

  buzzer.addMelody(melody_jingle_bells);

  buzzer.playMelody();         // play แบบ วนไปเรื่อยๆ
  
  // buzzer.playMelody(1);     // หากจะ play แบบรอบเดียว

  // หากจะ play แบบ 2 รอบ และ เมื่อเล่นเสร็จให้ทำอะไรต่อ
  // buzzer.playMelody(2, [](){
  //   /* เมื่อเล่นจบให้ทำอะไรวางตรงนี้ */
  //   Serial.println("[Melody] Done");
  // });

  // buzzer.pauseMelody();     // หากจะ pause หยุดชั่วคราว
  // buzzer.playMelody();      // หากจะ กลับมาเล่นต่อจากที่เคย pause ไว้
  // buzzer.stopMelody();      // หากจะ stop ยกเลิกการ play เลย

}

void loop(){

}
```

## Melody Note (โน้ตสำหรับทำ melody)

```cpp
NOTE_NO   // Rest Note (เงียบเสียง)
NOTE_B0 
NOTE_C1   
NOTE_CS1   
NOTE_D1   // โด
NOTE_DS1  // โด #
NOTE_E1   // เร
NOTE_F1   // มี
NOTE_FS1  // มี #
NOTE_G1   // ฟา
NOTE_GS1  // ฟา #
NOTE_A1   // ซอล
NOTE_AS1  // ซอล #
NOTE_B1   // ลา
NOTE_C2   // ที
NOTE_CS2  // ที #
NOTE_D2
NOTE_DS2 
NOTE_E2
NOTE_F2
NOTE_FS2 
NOTE_G2
NOTE_GS2 
NOTE_A2
NOTE_AS2 
NOTE_B2
NOTE_C3
NOTE_CS3 
NOTE_D3
NOTE_DS3 
NOTE_E3
NOTE_F3
NOTE_FS3 
NOTE_G3
NOTE_GS3 
NOTE_A3
NOTE_AS3 
NOTE_B3
NOTE_C4
NOTE_CS4 
NOTE_D4
NOTE_DS4 
NOTE_E4
NOTE_F4
NOTE_FS4 
NOTE_G4
NOTE_GS4 
NOTE_A4
NOTE_AS4 
NOTE_B4
NOTE_C5
NOTE_CS5 
NOTE_D5
NOTE_DS5 
NOTE_E5
NOTE_F5
NOTE_FS5 
NOTE_G5
NOTE_GS5 
NOTE_A5
NOTE_AS5 
NOTE_B5
NOTE_C6
NOTE_CS6 
NOTE_D6
NOTE_DS6 
NOTE_E6
NOTE_F6
NOTE_FS6 
NOTE_G6
NOTE_GS6 
NOTE_A6
NOTE_AS6 
NOTE_B6
NOTE_C7
NOTE_CS7 
NOTE_D7
NOTE_DS7 
NOTE_E7
NOTE_F7
NOTE_FS7 
NOTE_G7
NOTE_GS7 
NOTE_A7
NOTE_AS7 
NOTE_B7
NOTE_C8
NOTE_CS8 
NOTE_D8
NOTE_DS8 
```

## Melody Raw Duration
<p align="center">
  <img src="images/note_raw_duration.png" alt="image"/>
</p>
  
## Melody BPM (Beat Per Minute)
BPM ค่า จังหวะดนตรีว่ากี่ Beat (ครั้ง) ต่อนาที ของ โน้ตตัวดำ (Quarter Note)  
โดยสามารถใช้ค่า BPM จากโน้ตเพลง  

<p align="center">
  <img src="images/bpm_of_quarter_note.png" alt="image"/>
</p>
  
## True Duration Equation (สมการค่า Duration จริง)

สมการค่า Duration จริง คำนวนตามสูตร  
  
<img src="http://www.sciweavers.org/tex2img.php?eq=TrueDuration%20%3D%20%20%20%5Cfrac%7B%20RawDuration%20%5Ctimes%20%20%2060000%7D%7B%20%28200%20%20%5Ctimes%20BPM%29%20%7D%20%20%5Bmillisecond%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="TrueDuration =   \frac{ RawDuration \times   60000}{ (200  \times BPM) }  [millisecond]" width="450" height="46" />  
  
  
### ตัวอย่าง
หากโน้ตเพลง มี BPM สำหรับ โน้ตตัวดำ 135 ครั้งต่อนาที  
  
และ ในโน้ตเพลง มี โน้ต F (ฟา) เปฺ็นโน้ตตัวดำ (Quarter Note) อยู่  
ฉะนั้น โน้ต F (ฟา) ที่เป็นโน้ตตัวดำ จะใช้เวลาในการเล่นจริง 444 มิลลิวินาที  
  
<img src="http://www.sciweavers.org/tex2img.php?eq=TrueDuration%20%3D%20%5Cfrac%7B%20200%20%20%5Ctimes%2060000%7D%7B%28200%20%5Ctimes%20135%29%7D%0A%3D%20%20444%20ms&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="TrueDuration = \frac{ 200  \times 60000}{(200 \times 135)}=  444 ms" width="335" height="46" />
  
  
และ หากในโน้ตเพลง มีโน้ต D (โด) เป็นโน้ตตัวขาว (Half Note) อยู่  
ฉะนั้น โน้ต D (โด) ที่เป็นโน้ตตัวขาว จะใช้เวลาในการเล่นจริง 888 มิลลิวินาที  
  
<img src="http://www.sciweavers.org/tex2img.php?eq=TrueDuration%20%3D%20%5Cfrac%7B%20400%20%20%5Ctimes%2060000%7D%7B%28200%20%5Ctimes%20135%29%7D%0A%3D%20%20888%20ms&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="TrueDuration = \frac{ 400  \times 60000}{(200 \times 135)}=  888 ms" width="335" height="46" />
  


## About 

### Version 1.0
BlynkGO  
22/03/22

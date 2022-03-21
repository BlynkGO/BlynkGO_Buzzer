# BlynkGO_Buzzer
 ESP32 Buzzer with beep and melody  by non-blocking

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
```

## About 

### Version 1.0
BlynkGO  
22/03/22

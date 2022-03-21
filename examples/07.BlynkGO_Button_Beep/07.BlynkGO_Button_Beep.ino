#include <BlynkGOv2.h>
#include <BlynkGO_Buzzer.h>

GContainer cont_btn;
  GButton btn1("ร้อน", cont_btn);
  GButton btn2("ปกติ", cont_btn);
  GButton btn3("เย็น", cont_btn);
  GButton btn4("Alarm", cont_btn);

Buzzer  buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();

  BlynkGO.begin();
  BlynkGO.fillScreen(TFT_BLUE, TFT_CYAN);

  cont_btn.layout(LAYOUT_ROW_M);
  cont_btn.padding(0,0,0,0,20);
  cont_btn.opa(0);

    btn1.size(80,80);
    btn1.corner_radius(20);
    btn1.color(TFT_ORANGE);
    btn1.onClicked([](GWidget*widget){
      buzzer.beep(1);  // ให้ beep 1 ครั้ง
      // จะให้ทำอะไรวางตรงนี้      
    });

    btn2.size(80,80);
    btn2.corner_radius(20);
    btn2.color(TFT_GREEN);
    btn2.onClicked([](GWidget*widget){
      buzzer.beep(2);  // ให้ beep 2 ครั้ง
      // จะให้ทำอะไรวางตรงนี้
    });

    btn3.size(80,80);
    btn3.corner_radius(20);
    btn3.color(TFT_BLUE);
    btn3.onClicked([](GWidget*widget){
      buzzer.beep(3);  // ให้ beep 3 ครั้ง
      // จะให้ทำอะไรวางตรงนี้
    });

    btn4.size(80,80);
    btn4.corner_radius(20);
    btn4.color(TFT_RED);
    btn4.onClicked([](GWidget*widget){
      static bool beep_mode;
      (beep_mode=!beep_mode)? buzzer.beep(): buzzer.stop();
      // จะให้ทำอะไรวางตรงนี้
    });
}

void loop(){
  BlynkGO.update();
}


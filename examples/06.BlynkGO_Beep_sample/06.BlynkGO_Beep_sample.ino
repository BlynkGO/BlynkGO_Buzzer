#include <BlynkGOv2.h>
#include <BlynkGO_Buzzer.h>

GLabel  label;
GButton btn_beep(SYMBOL_PLAY);
Buzzer  buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();

  BlynkGO.begin();
  BlynkGO.fillScreen(TFT_BLUE, TFT_CYAN);

  btn_beep.size(80,80);
  btn_beep.corner_radius(20);
  btn_beep.color(TFT_GREEN);
  btn_beep.onClicked([](GWidget*widget){
    static bool beep_mode; 
    if(beep_mode = !beep_mode) {
      buzzer.beep(); btn_beep = SYMBOL_STOP; btn_beep.color(TFT_RED);
    } else{
      buzzer.stop(); btn_beep = SYMBOL_PLAY; btn_beep.color(TFT_GREEN);
    }
  });

  label.align(ALIGN_TOP,0,20);
  label.font(prasanmit_25);
  static GTimer timer_lb;
  timer_lb.setInterval(1000, [](){
    static int counter;
    label = "Beep ทำงานไป โดยสิ่งๆก็ยังทำงานต่อไปได้ : " + String(++counter);
  });

}

void loop(){
  BlynkGO.update();
}

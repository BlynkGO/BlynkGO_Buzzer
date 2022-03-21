#include <BlynkGOv2.h>
#include <BlynkGO_Buzzer.h>

IMG_DECLARE(img_demonslayer);
MELODY_DECLARE(melody_demonslayer);

GImage  background(img_demonslayer);
GButton btn_melody(SYMBOL_PLAY);
GContainer cont_bpm;
  GLabel  lb_bpm(cont_bpm);
  GSlider slider_bpm(cont_bpm);
  GAnimation anim_cont_bpm;

Buzzer  buzzer(23);              // กำหนดขา pin

void setup(){
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();

  buzzer.addMelody(melody_demonslayer);

  background.align_center();
  background.clickable(true);
  background.onClicked([](GWidget*widget){
    
  });
  
  btn_melody.size(80,80);
  btn_melody.corner_radius(20);
  btn_melody.color(TFT_GREEN);  
  btn_melody.onClicked([](GWidget*widget){
    static bool beep_mode; 
    if(beep_mode = !beep_mode) {
      buzzer.playMelody();  btn_melody = SYMBOL_PAUSE; btn_melody.color(TFT_RED);
    } else{
      buzzer.pauseMelody(); btn_melody = SYMBOL_PLAY; btn_melody.color(TFT_GREEN);
    }
  });

  cont_bpm.opa(160);
  cont_bpm.corner_radius(20);
  cont_bpm.layout(LAYOUT_COL_R);  // จัด layout เรียงแบบ column โดยชิดขวาตรงกัน
  cont_bpm.padding(5,10,30,30,5); // ช่องไฟบน ล่าง ซ้าย ขวา ระหว่างภายใน
  cont_bpm.align(ALIGN_BOTTOM, 0, -5);
  
    lb_bpm =  StringX::printf("BPM %d", buzzer.bpm());
    lb_bpm.color( TFT_COLOR_HSV(240,100,50) );  // น้ำเงินเข้ม
    slider_bpm.range(10,400);
    slider_bpm.width(360);
    slider_bpm.color(TFT_BLUE);
    slider_bpm.onValueChanged([](GWidget* widget){
      Serial.println(slider_bpm.value());  // ดึงค่า มาแสดงบน Serial Monitor
      lb_bpm = StringX::printf("BPM %d", slider_bpm.value());
      buzzer.bpm(slider_bpm.value());
    });  
    slider_bpm = buzzer.bpm();

  //----------------------------------------------------
  anim_cont_bpm.init(cont_bpm, [](GWidget*widget, int16_t v){
    cont_bpm  .opa(map(v,0,255,0,160));
    lb_bpm    .opa(v);
    slider_bpm.opa(v);
  }, 0, 255, 3000);
  anim_cont_bpm.create();
}

void loop(){
  BlynkGO.update();
}

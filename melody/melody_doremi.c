#include "melody_struct.h"

// -------------------------------------------
// ค่า Raw Duration ของ Note  ( Note Duration)
// -------------------------------------------
// whole note  (โนตตัวกลม)      = 800 durations
// haft note   (โนตตัวขาว)      = 400 durations
// quarter note (โนตตัวดำ)      = 200 durations
// eighth note (โนตเขบ็ต 1 ชั้น)  = 100 durations
// sixteenth note(โนตเขบ็ต 2 ชั้น)= 50 durations

// -------------------------------------------
// BPM :  ค่า Beat ต่อ นาที ของ Quarter Note  
// -------------------------------------------
// BPM 296   // คือ ค่า จน.ครั้ง beat ต่อนาทีของโน้ตตัวดำ

// -------------------------------------------
// สูตรค่า True Duration  (ms มิลลิวินาที)
// -------------------------------------------
// สูตร ระยะเวลาที่ Note ตัวนึงๆจะเล่นนานจริง 
// โดยคำนวณ จากค่า Raw Duration และ BPM ที่กำหนด
//
// True_Duration = Raw_Duration * 60000ms/ (200*BPM)  [ms]
//
//  - หาก BPM ยิ่ง มาก  โน้ตแต่ละตัวเวลา play ระยะเวลาจะสั้นลง
//  - หาก BPM ยิ่ง น้อย  โน้ตแต่ละตัวเวลา play ระยะเวลาจะสั้นยาวขึ้น
//


const PROGMEM melody_note_t doremi_notes[73]  = {
  { NOTE_D4,  800}, // Doe
  { NOTE_E4,  200}, // a
  { NOTE_FS4, 800}, // deer
  { NOTE_D4,  200}, // a
  { NOTE_FS4, 400}, // fe-
  { NOTE_D4,  400}, // male
  { NOTE_FS4, 400}, // deer
  { NOTE_NO,  400},
  { NOTE_E4,  800}, // Ray
  { NOTE_FS4, 800}, // a
  { NOTE_G4,  200}, // drop
  { NOTE_G4,  200}, // of
  { NOTE_FS4, 200}, // gold-
  { NOTE_E4,  200}, // en
  { NOTE_G4,  800}, // sun
  { NOTE_NO,  400},
  { NOTE_FS4, 800}, // Me
  { NOTE_G4,  200}, // a
  { NOTE_A4,  800}, // name
  { NOTE_FS4, 200}, // I
  { NOTE_A4,  400}, // call
  { NOTE_FS4, 400}, // my-
  { NOTE_A4,  400}, // self
  { NOTE_NO,  400},
  { NOTE_G4,  800}, // Far
  { NOTE_A4,  200}, // a
  { NOTE_B4,  200}, // long
  { NOTE_B4,  200}, // long
  { NOTE_A4,  200}, // way
  { NOTE_G4,  200}, // to
  { NOTE_B4,  800}, // run
  { NOTE_NO,  400},
  { NOTE_A4,  800}, // Sew
  { NOTE_D4,  200}, // a
  { NOTE_E4,  200}, // nee-
  { NOTE_FS4, 200}, // dle
  { NOTE_G4,  200}, // pul-
  { NOTE_A4,  200}, // ling
  { NOTE_B4,  800}, // thread
  { NOTE_NO,  400},
  { NOTE_B4,  800}, // La
  { NOTE_E4,  200}, // a
  { NOTE_FS4, 200}, // note
  { NOTE_G4,  200}, // to
  { NOTE_A4,  200}, // fol-
  { NOTE_B4,  200}, // low
  { NOTE_CS5, 800}, // sew
  { NOTE_NO,  400},
  { NOTE_CS5, 800}, // Tea
  { NOTE_FS4, 200}, // I
  { NOTE_G4,  200}, // drink
  { NOTE_A4,  200}, // with
  { NOTE_B4,  200}, // jam
  { NOTE_C5,  200}, // and
  { NOTE_D5,  800}, // bread
  { NOTE_NO,  400},
  { NOTE_D5,  200}, // That
  { NOTE_CS5, 200}, // will
  { NOTE_B4,  400}, // bring
  { NOTE_G4,  400}, // us
  { NOTE_CS5, 400}, // back
  { NOTE_A4,  400}, // to
  { NOTE_D5,  800}, // Doe
  { NOTE_NO,  400},
  { NOTE_D4,  400}, // Doe
  { NOTE_E4,  400}, // Ray
  { NOTE_FS4, 400}, // Me
  { NOTE_G4,  400}, // Far
  { NOTE_A4,  400}, // Sew
  { NOTE_B4,  400}, // La
  { NOTE_CS5, 400}, // Tea
  { NOTE_D5,  400}, // Doe
  { NOTE_NO, 1600},
};

const melody_t melody_doremi = {
  .notes  = doremi_notes,
  .size   = 73,
  .bpm    = 296,
};

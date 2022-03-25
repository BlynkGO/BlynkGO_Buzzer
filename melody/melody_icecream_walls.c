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
// BPM 110   // คือ ค่า จน.ครั้ง beat ต่อนาทีของโน้ตตัวดำ

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

const PROGMEM melody_note_t icecream_walls_notes[56] = {
{ NOTE_E5,  200},
{ NOTE_G5,  100},
{ NOTE_C5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  200},
{ NOTE_C6,  100},
{ NOTE_F5,  300},
{ NOTE_NO,  200},
{ NOTE_B5,  100},
{ NOTE_B5,  100},
{ NOTE_C6,  100},
{ NOTE_D6,  100},
{ NOTE_C6,  400},
{ NOTE_E5,  200},
{ NOTE_G5,  100},
{ NOTE_C5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  200},
{ NOTE_C6,  100},
{ NOTE_F5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  100},
{ NOTE_B5,  100},
{ NOTE_G5,  100},
{ NOTE_A5,  100},
{ NOTE_B5,  100},
{ NOTE_D5,  100},
{ NOTE_C5, 1000},
{ NOTE_NO,  200},
{ NOTE_E5,  200},
{ NOTE_G5,  100},
{ NOTE_C5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  200},
{ NOTE_C6,  100},
{ NOTE_F5,  300},
{ NOTE_NO,  200},
{ NOTE_B5,  100},
{ NOTE_C6,  100},
{ NOTE_D6,  100},
{ NOTE_C6,  400},
{ NOTE_E5,  200},
{ NOTE_G5,  100},
{ NOTE_C5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  200},
{ NOTE_C6,  100},
{ NOTE_F5,  300},
{ NOTE_NO,  200},
{ NOTE_A5,  100},
{ NOTE_B5,  100},
{ NOTE_G5,  100},
{ NOTE_A5,  100},
{ NOTE_B5,  100},
{ NOTE_D5,  100},
{ NOTE_C5, 1000},
{ NOTE_NO, 1600},
};

const melody_t melody_icecream_walls = {
  .notes  = icecream_walls_notes,
  .size   = 56,
  .bpm    = 110,
};

#include "pitches.h"

int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;

int BUZZ1 = D10;
int BUZZ2 = D9;
int BUZZ3 = D8;

int EnteredSequence[10];
int SequenceLength = 0;    
unsigned long LastPressTime = 0; 
bool Recording = true;          

unsigned long LastDebounceTime = 0;
const unsigned long DebounceDelay = 50;

int melody1_notes[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int melody1_durations[] = {4, 4, 4, 4, 4, 4, 4, 2};

int melody2_notes[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5};
int melody2_durations[] = {2, 2, 2, 1};

int password1[] = {1, 2, 3};
int password1_length = 3;

int password2[] = {3, 2, 1, 3};
int password2_length = 4;

void setup() {

  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZ1, OUTPUT);
  pinMode(BUZZ2, OUTPUT);
  pinMode(BUZZ3, OUTPUT);

}

void loop() {
  unsigned long CurrentTime = millis();

  int PressedButton = GetPressedButton();

  if (PressedButton > 0 && Recording) {
  
    EnteredSequence[SequenceLength] = PressedButton; //records the sequence of buttons
    SequenceLength++;
    
    if (PressedButton == 1) digitalWrite(LED1, HIGH);
    if (PressedButton == 2) digitalWrite(LED2, HIGH);
    if (PressedButton == 3) digitalWrite(LED3, HIGH);
    
    delay(150);
    
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
    LastPressTime = CurrentTime;
  }
  
  if (Recording && SequenceLength > 0 && (CurrentTime - LastPressTime) >= 3000) {
    Recording = false;
    
    for (int i = 0; i < SequenceLength; i++) {
      if (EnteredSequence[i] == 1) digitalWrite(LED1, HIGH);
      if (EnteredSequence[i] == 2) digitalWrite(LED2, HIGH);
      if (EnteredSequence[i] == 3) digitalWrite(LED3, HIGH);
      delay(200);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      delay(100);
    }
    
    PasswordCheckerAndPlayer();
    
    SequenceLength = 0;
    Recording = true;
    LastPressTime = CurrentTime;
  }
}

int GetPressedButton() {
  unsigned long CurrentTime = millis();
  
  if (CurrentTime - LastDebounceTime < DebounceDelay) return 0;
  
  if (digitalRead(BUT1) == LOW) {
    LastDebounceTime = CurrentTime;
    return 1;
  }
  if (digitalRead(BUT2) == LOW) {
    LastDebounceTime = CurrentTime;
    return 2;
  }
  if (digitalRead(BUT3) == LOW) {
    LastDebounceTime = CurrentTime;
    return 3;
  }
  return 0;
}

void PasswordCheckerAndPlayer() {
  // password 1
  if (SequenceLength == password1_length) {
    bool match = true;
    for (int i = 0; i < SequenceLength; i++) {
      if (EnteredSequence[i] != password1[i]) {
        match = false;
        break;
      }
    }
    if (match) {
      MelodyOnAllBuzzers(melody1_notes, melody1_durations, 8);
      return;
    }
  }
  
  if (SequenceLength == password2_length) {
      bool match = true;
      for (int i = 0; i < SequenceLength; i++) {
        if (EnteredSequence[i] != password2[i]) {
          match = false;
          break;
        }
      }
    if (match) {
      HappyChord(melody2_notes, melody2_durations, 4);
      return;
    }
  }

  for (int i = 0; i < 3; i++) {
    tone(BUZZ1, NOTE_C4, 200);
    tone(BUZZ2, NOTE_C4, 200);
    tone(BUZZ3, NOTE_C4, 200);
    delay(300);
    noTone(BUZZ1);
    noTone(BUZZ2);
    noTone(BUZZ3);
    delay(100);
  }
}

void MelodyOnAllBuzzers(int notes[], int durations[], int length) {
  for (int i = 0; i < length; i++) {
    int duration = 1000 / durations[i]; // this decides the tempo
    tone(BUZZ1, notes[i], duration);
    tone(BUZZ2, notes[i], duration);
    tone(BUZZ3, notes[i], duration);
    delay(duration * 1.3);
    noTone(BUZZ1);
    noTone(BUZZ2);
    noTone(BUZZ3);
  }
}

void  HappyChord(int notes[], int durations[], int length) {
  for (int i = 0; i < length; i++) {
    int duration = 1000 / durations[i];

    tone(BUZZ1, notes[i], duration);  
    tone(BUZZ2, notes[i] + 4, duration);
    tone(BUZZ3, notes[i] + 7, duration);
    delay(duration * 1.3);
    noTone(BUZZ1);
    noTone(BUZZ2);
    noTone(BUZZ3);
  }
}

void SadChord(int notes[], int durations[], int length) {
  for (int i = 0; i < length; i++) {
    int duration = 1000 / durations[i];
    tone(BUZZ1, notes[i]);
    tone(BUZZ2, notes[i] + 3);
    tone(BUZZ3, notes[i] + 7);
    delay(duration * 1.3);
    noTone(BUZZ1);
    noTone(BUZZ2);
    noTone(BUZZ3);
  }
}

void POWERCHORD(int notes[], int durations[], int length) {
  for (int i = 0; i < length; i++) {
    int duration = 1000 / durations[i];
    tone(BUZZ1, notes[i]);
    tone(BUZZ2, notes[i] + 7);
    tone(BUZZ3, notes[i] + 12);
    delay(duration * 1.3);
    noTone(BUZZ1);
    noTone(BUZZ2);
    noTone(BUZZ3);
  }
}


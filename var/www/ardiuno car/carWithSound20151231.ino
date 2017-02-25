#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


char c;
void setup(){

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }


  Serial.begin(9600);
  Serial.println("Arduino started");
  pinMode(12, OUTPUT); // backward pin - used by b and c
  pinMode(11, OUTPUT); // left pin - used by l and m
  pinMode(10, OUTPUT); // right pin - used by r and s
  pinMode(9, OUTPUT);  // forward pin - used by f and g
}

  void loop(){
  if (Serial.available() > 0)
    {
    c = Serial.read();
    // Serial.println(c);
  }
  else
    {
    delay(1);
  }
  if (c=='f')
    {
    Serial.println("forward on");
    digitalWrite(9, HIGH);
      for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  }
  if (c=='g')
    {
    Serial.println("forward off");
    digitalWrite(9, LOW);
  }
  if (c=='b')
    {
    Serial.println("back on");
    digitalWrite(12, HIGH);
  }
  if (c=='c')
    {
    Serial.println("back off");
    digitalWrite(12, LOW);
  }
  if (c=='l')
    {
    Serial.println("left on");
    digitalWrite(11, HIGH);
  }
  if (c=='m')
    {
    Serial.println("left off");
    digitalWrite(11, LOW);
  }
  if (c=='r')
    {
    Serial.println("right on");
    digitalWrite(10, HIGH);
  }
  if (c=='s')
    {
    Serial.println("right off");
    digitalWrite(10, LOW);
  }
  c='\0';
}

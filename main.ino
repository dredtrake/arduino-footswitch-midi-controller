#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <Bounce2.h>

#define MIDI_CHANNEL 1
#define BOUNCE_TIME 10 // Debounce Time (in milliseconds)

//MIDI Channel
const uint8_t controls[] = { 2, 3, 4, 5, 6, 7 };
const uint8_t ledPins[] = { 8, 9, 10, 11, 12, 13 };
const uint8_t notes[] = { 100, 101, 102, 103, 104, 105 };
int ledStates[] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

Bounce2::Button buttons[sizeof(controls)];

//Setup
void setup() {
  for (int i = 0; i < sizeof(controls); i++){
    buttons[i].attach(controls[i], INPUT_PULLUP);
    buttons[i].interval(BOUNCE_TIME);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], ledStates[i]); 
  }
}

//Main Loop
void loop() {
  for (int i = 0; i < sizeof(controls); i++){
    buttons[i].update();
    if ( buttons[i].changed() ) {
      int deboucedInput = buttons[i].read();
      if ( deboucedInput == LOW ) {
        ledStates[i] = !ledStates[i];
        digitalWrite(ledPins[i], ledStates[i]); // WRITE THE NEW ledState
        noteOn(MIDI_CHANNEL, notes[i], 127);
      }
    }
  }
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | 1, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

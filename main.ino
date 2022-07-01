#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <Bounce2.h>

#define MIDI_CHANNEL 1
#define BOUNCE_TIME 15 // Debounce Time (in milliseconds)

// wiring
const uint8_t controls[] = { 7, 8 };
const uint8_t ledPins[] = { 10, 11 };
const uint8_t notes[] = { 108, 109 };
int ledStates[] = { LOW, LOW };

Bounce2::Button buttons[sizeof(controls)];

//Setup
void setup() {
  for (int i = 0; i < sizeof(controls); i++){
    buttons[i].attach(controls[i], INPUT_PULLUP);
    buttons[i].interval(5);
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

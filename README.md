# arduino-footswitch-midi-controller

🦶🎸🤘🎼🎵♬

The code works for 6 footswitches, but just remove/add new values in the arrays and the rest will do it's job (set correct pin numbers, note and states for leds). -> if your card don't have enough pins, you might want to use a multiplexer.

<img src="Images/footswitch.jpg?raw=truejpg" alt="spst footswitch" width="400"/>

The wiring is very simple, be careful to add a 22kΩ resistor to the + of the led (double check!!).
All ground wires are plugged to a common ground on the arduino.

<img src="Images/schematic.jpg?raw=truejpg" alt="DAW preferences" width="800"/>

I am using the arduino leonardo, but please check if your card works with the 2 libraries bellow (arduino uno don't recognize MIDIUSB signal by default and needs to use some softwares to make the bridge)
Be sure to install MidiUSB & Bounce2 on the arduino.

```
const uint8_t controls[] = { 2, 3, 4, 5, 6, 7 }; // the footswitches are plugged from pin 2 to 7
const uint8_t ledPins[] = { 8, 9, 10, 11, 12, 13 }; // the leds are plugged from pin 8 to 13
const uint8_t notes[] = { 100, 101, 102, 103, 104, 105 }; // for our purpose this value doesn't really matter but it needs a note by button
int ledStates[] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}; // the state of the leds. Needs one by input. On by default. Use 'LOW' for having them off by default
```

<img src="Images/step-1.jpg?raw=truejpg" alt="in progress step" width="980"/>

<img src="Images/step-2.jpg?raw=truejpg" alt="final pluggin" width="980"/>

<img src="Images/step-3.jpg?raw=truejpg" alt="final setup with enclosure" width="980"/>

## Once installed it should be recognize in any DAW.

Select the device in the input column (we don't need to output anything in this project).

Be sure to select `remote` in the input options of the device of the daw.

<img src="Images/preferences-daw.png?raw=truejpg" alt="DAW preferences" width="400"/>

You should be able to assign any button to a midi control.

Have fun !

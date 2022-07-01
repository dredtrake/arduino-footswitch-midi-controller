# arduino-footswitch-midi-controller

The code works for 2 footswitches at the moment, but just add new values in the arrays and the rest will do it's job (set correct pin numbers, note and states for leds).
🦶🎸🤘🎼🎵♬

<img src="Images/footswitch.jpg?raw=truejpg" alt="spst footswitch" width="400"/>

The wiring is very simple, be careful to add a 22kΩ resistor to the + of the led (double check!!).
All ground wires are plugged to a common ground on the arduino.

I using the leonardo, but please check if your works with the 2 libraries bellow
Be sure to install MidiUSB & Bounce2 on the arduino

```
const uint8_t controls[] = { 7, 8 }; // the 2 footswitch are on pin 7 & 8
const uint8_t ledPins[] = { 10, 11 }; // Leds are on pins 10 & 11
const uint8_t notes[] = { 108, 109 }; // 2 random note to be played
```

<img src="Images/setup.jpg?raw=truejpg" alt="spst setup" width="400"/>

## once installed it should be recognize in any DAW.

Be sure to set up sync in the input options of the device of the daw.

You should be able to assign any button to a midi control.

Have fun !

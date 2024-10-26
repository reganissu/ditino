# Ditino

This repository contains the example program to use your Ditino shield.

https://github.com/user-attachments/assets/75744881-a83e-4b6f-8f4a-8e8f81cb46c6

# Compilation and upload

Load this repository into the Arduino IDE. Install from the boards manager this platform:

- Arduino UNO R4 Boards (v1.2.2)

and from the library manager:

- ArduinoGraphics (v1.1.3)
- R4_Touch (v1.1.0)

Compile and upload the sketch.

## Technical details

Ditino leverages the native capacitive touch sensors of the Arduino UNO R4 Wifi. The logic for accessing these native features of the Renesas MCU is implemented in the [R4_Touch](https://github.com/delta-G/R4_Touch) library.

This sketch uses the free running mode of measurements: the MCU continuously measures the capacitors and returns the results via interrupts.

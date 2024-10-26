#include "R4_Touch.h"
#include "Arduino_LED_Matrix.h"

#define NUM_SENSORS 4

uint32_t zones[NUM_SENSORS][3] = {
  {0x00700700, 0x70070000, 0x0},
  {0x0, 0x00000070, 0x07007007},
  {0x03803803, 0x80380000, 0x0},
  {0x0, 0x00000380, 0x38038038},

};

uint8_t sensor_pins[] = {6,2,8,3};

TouchSensor sensors[NUM_SENSORS];

ctsu_pin_settings_t settings[NUM_SENSORS] = {
 {.div=CTSU_CLOCK_DIV_16, .gain=CTSU_ICO_GAIN_100, .ref_current=0, .offset=282, .count=1},
  {.div=CTSU_CLOCK_DIV_18, .gain=CTSU_ICO_GAIN_100, .ref_current=0, .offset=154, .count=1},
   {.div=CTSU_CLOCK_DIV_16, .gain=CTSU_ICO_GAIN_100, .ref_current=0, .offset=202, .count=1},
  {.div=CTSU_CLOCK_DIV_16, .gain=CTSU_ICO_GAIN_100, .ref_current=0, .offset=152, .count=1},

};

ArduinoLEDMatrix matrix;



void setup() {

  Serial.begin(115200);
  while(!Serial);
  Serial.println("\n\n *** 8_touch.ino ***\n\n");

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensors[i].begin(sensor_pins[i], 10000);
    sensors[i].applyPinSettings(settings[i]);
    // sensors[i].setMeasurementCount(10);
    // sensors[i].setSensorOffset(offsets[i]);
  }
  
  TouchSensor::start();
  matrix.begin();
}


void loop() {
  uint32_t matrixOut[3] = {0};
  for (int i=0; i<NUM_SENSORS; i++){
    if(sensors[i].read()){
      for (int j=0; j<3; j++){
        matrixOut[j] |= zones[i][j];
      }
    }
  }
  matrix.loadFrame(matrixOut);
  delay(100);


}

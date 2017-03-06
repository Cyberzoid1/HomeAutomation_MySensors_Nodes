#include <Arduino.h>
#include "MySensorsNode.h"
#include "Node_LR_Door.h"
#include "myDebug.h"

void buttoncheck(){
  //basic debounce
  if (digitalRead(btnPin)){ //analogRead(btnPin) > 700) {
    debug1_sprintln(F("Setup button pressed"));
    delay(100); //simple debounce
    lightServoToggle();
  }
} //end buttoncheck()

// This function checks the real world light state and returns 1/0
int UpdateLightSensor() {
  static int count = 21;
  LastLightSensor = LightSensor; 

  /* Read sensor*/ LightSensor = LastLightCommand;
  
  if (LastLightSensor != LightSensor || count <=0) {
    SendCurrentState2Controller();
    Serial.print("Sending State to controller: ");
    Serial.println(LightSensor);
    count = 21; // with the main loop 500ms wait, this trips every 10s
  }
  count--;
  return LightSensor;
}

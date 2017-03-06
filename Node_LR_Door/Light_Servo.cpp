#include <SoftwareServo.h>
#include <Arduino.h>
#include <sw_task.h>
#include "Node_Nick_Door_V1.h"
#include "MySensorsNode.h"
#include "myDebug.h"

#ifdef SERVO_ENABLE
  SoftwareServo myservo;
#endif

//servo
int pos_On     = 160; //180; //"up"
int pos_Off    = 20;  //17;  //"down"
int pos_Neutral = 85;

void lightServoInitialization() {
  #ifdef SERVO_ENABLE
    myservo.setMinimumPulse(512);
    myservo.setMaximumPulse(2400);
  #endif
  lightServoSet(pos_Neutral);
}

void lightServo(int p) {
  if (p == 1)
    lightServoSet(pos_On);
  else if (p ==0)
    lightServoSet(pos_Off);
  lightServoSet(pos_Neutral);
}
void lightServoSet(int pos){
  #ifdef SERVO_ENABLE
    myservo.attach(Servo_Pin);
    myservo.write(pos);
    sw_task tservo_delay(servoWaitDelay);
//    MSDelay(servoWaitDelay)
    while(!tservo_delay.tupdate()){
      SoftwareServo::refresh();
      MSProcess();
    }
    myservo.detach();
  #endif
}

void lightServoToggle(){
  if (LightSensor == 1){ //if on, turn off
      debug1_sprintln(F("Toggling OFF."));
      lightServo(0);
    }
    else{ //if off, turn on
      debug1_sprintln(F("Toggling ON."));
      lightServo(1);
    }
}

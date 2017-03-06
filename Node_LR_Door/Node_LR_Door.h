/*
 * This file serves as the header for both Light_Servo.cpp and Aux_IO.cpp
 */
 
#ifndef Node_Nick_Door_V1_H
#define Node_Nick_Door_V1_H

#define SERVO_ENABLE
#define debug1 // comment this line out to disable serial. Or when programming for attiny.

//pins
#define Servo_Pin  3
#define LED_Pin 6  // UNO
#define btnPin 7     // for button

//servo
#define servoWaitDelay  700  //wait for servo to move to position

extern int LastLightCommand;
extern int LightSensor;
extern int LastLightSensor;

//Function Prototypes
// In Light_Servo.cpp
void lightServoInitialization();
void lightServo(int p);
void lightServoSet(int pos);
void lightServoToggle();
// In Aux_IO.cpp
int UpdateLightSensor();
void buttoncheck();

#endif

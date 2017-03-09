/**
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 *******************************
 * 
 * DESCRIPTION
 * This sketch provides an example how to implement a Dimmable Light 
 * 
 */
 
#include <SPI.h>
#include "MySensorsNode.h"    // Must be called before MyConfig.h
#include <MyConfig.h> // mysensors related
#include <MySensors.h>
#include <sw_task.h>
//#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "Node_LR_Door.h"
#include "myDebug.h"

int LastLightCommand=LIGHT_OFF; // last command basicaly
int LightSensor=LIGHT_OFF;
int LastLightSensor=LIGHT_OFF;

sw_task tLightSensor(500);

void setup()  
{
  MySensorsSetup();
  lightServoInitialization();
  Serial.println( "Node ready to receive messages..." );  
}

void loop()      
{
  MSProcess();
  // check button
  // check lightStatusSensor
  if (tLightSensor.tupdate()){
  }
}

void SetCurrentState2Hardware()
{
  if (LastLightCommand==LIGHT_OFF) {
     Serial.println( "Light state: OFF" );
     lightServo(0);
  }
  else {
     Serial.println( "Light state: ON" );
     lightServo(1);
  }
}

void Serial_Event() {
  const int serial_dat_max = 5;
  char serial_dat[serial_dat_max];
  for (int i = 0; i < serial_dat_max; i++) {
    serial_dat[i] = '\0';
  }
  int serial_count = 0;
  int serial_pos = 90;
  if (Serial.available()) {
    Serial.print("Recived: ");
    while (Serial.available()) {
      byte inByte = 0;
      inByte = Serial.read();
      Serial.print(char(inByte));
      // Test if digit
      if (inByte < 48 || inByte > 57 || serial_count >= serial_dat_max ) {
        Serial.println("\tInvalid");
        return;
      }
      serial_dat[serial_count] = inByte;
      serial_count++;
    }
    serial_pos = atoi(serial_dat);
    Serial.print("\tSerial pos: ");
    Serial.println(serial_pos);
    if (serial_pos >=0 && serial_pos <= 180)
      lightServoSet(serial_pos);
    else
      Serial.println("Serial pos: out of range");
  }
}


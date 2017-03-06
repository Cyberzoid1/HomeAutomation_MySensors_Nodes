#include <SPI.h>
#include "MySensorsNode.h"    // Must be called before MyConfig.h
#include <MyConfig.h> // mysensors related
#include <MySensors.h>
#include "Node_LR_Door.h"
#include "myDebug.h"

MyMessage lightMsg(CHILD_ID_LIGHT, V_LIGHT);
MyMessage lightStatusMsg(CHILD_ID_LIGHT_STATUS, V_STATUS);

void MySensorsSetup()
{
  // Send the Sketch Version Information to the Gateway
  sendSketchInfo(SN, SV);
  
    //Retreive our last light state from the eprom
  int LightState=loadState(EPROM_LIGHT_STATE); 
  if (LightState<=1) {
    LastLightCommand=LightState;
  }

  present(CHILD_ID_LIGHT, V_STATUS );
//  SetCurrentState2Hardware(); // needed for direct version. Now we just sense it
  SendCurrentState2Controller(); 
}

void MSProcess() {
  // happens internally
}

// Depreciated, convert to MSWait.
void MSDelay(int t) {
  wait(t);
}
// same as above but better name
void MSWait(int t) {
  wait(t);
}

void MSSleep(int t) {
  sleep(t);
}

// send the current light sensor value to controller
void SendCurrentState2Controller()
{
  send(lightStatusMsg.set(LightSensor));
}

void receive(const MyMessage &message)
{
  if (message.type == V_LIGHT) {
    Serial.println( "V_LIGHT command received..." );
    
    int lstate= atoi( message.data );
    if ((lstate<0)||(lstate>1)) {
      Serial.println( "V_LIGHT data invalid (should be 0/1)" );
      return;
    }
    LastLightCommand=lstate;
    saveState(EPROM_LIGHT_STATE, LastLightCommand);
    //Here you set the actual light state/level
    SetCurrentState2Hardware();
  }
  else {
    Serial.println( "Invalid command received..." );  
    return;
  }
}

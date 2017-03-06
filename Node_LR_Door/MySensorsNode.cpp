#include <SPI.h>
#include <MySensor.h>  
#include "MySensorsNode.h"
#include "Node_Nick_Door_V1.h"
#include "myDebug.h"

MySensor gw;
MyMessage lightMsg(CHILD_ID_LIGHT, V_LIGHT);
MyMessage lightStatusMsg(CHILD_ID_LIGHT_STATUS, V_STATUS);

void MySensorsSetup()
{
  gw.begin(MSIncomingMessage, NODE_ID, false);

  // Send the Sketch Version Information to the Gateway
  gw.sendSketchInfo(SN, SV);
  
    //Retreive our last light state from the eprom
  int LightState=gw.loadState(EPROM_LIGHT_STATE); 
  if (LightState<=1) {
    LastLightCommand=LightState;
  }

  gw.present(CHILD_ID_LIGHT, V_STATUS );
//  SetCurrentState2Hardware(); // needed for direct version. Now we just sense it
  SendCurrentState2Controller(); 
}

void MSProcess() {
  gw.process();
}

// Depreciated, convert to MSWait.
void MSDelay(int t) {
  gw.wait(t);
}
// same as above but better name
void MSWait(int t) {
  gw.wait(t);
}

void MSSleep(int t) {
  gw.sleep(t);
}

// send the current light sensor value to controller
void SendCurrentState2Controller()
{
  gw.send(lightStatusMsg.set(LightSensor));
}

void MSIncomingMessage(const MyMessage &message)
{
  if (message.type == V_LIGHT) {
    Serial.println( "V_LIGHT command received..." );
    
    int lstate= atoi( message.data );
    if ((lstate<0)||(lstate>1)) {
      Serial.println( "V_LIGHT data invalid (should be 0/1)" );
      return;
    }
    LastLightCommand=lstate;
    gw.saveState(EPROM_LIGHT_STATE, LastLightCommand);
    //Here you set the actual light state/level
    SetCurrentState2Hardware();
  }
  else {
    Serial.println( "Invalid command received..." );  
    return;
  }
}

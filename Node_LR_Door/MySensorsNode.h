


#include <SPI.h>

/*********************
 * MyConfig.h local settings
**********************/
#define MY_RADIO_NRF24

#include <MyConfig.h>
#include <MySensors.h>

/***************************
 * Node Settings 
****************************/
#define SN "LR Light Switch"
#define SV "1.0"
#define NODE_ID 5  // Refer to NySensors_Node_list.txt
#define CHILD_ID_LIGHT 1
#define CHILD_ID_LIGHT_STATUS 2

#define EPROM_LIGHT_STATE 1

#define LIGHT_OFF 0
#define LIGHT_ON 1


// Prototypes
void MySensorsSetup();
void MSProcess();
void MSDelay(int t);
void MSSleep(int t);
void SendCurrentState2Controller();
void SetCurrentState2Hardware();
void MSIncomingMessage(const MyMessage &message);

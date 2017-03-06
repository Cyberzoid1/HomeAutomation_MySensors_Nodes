//#define debug.h

//For softserial or built in serial
//#define myDebugSerial mySerial
#define myDebugSerial Serial

#ifdef debug1
  #define debug1_begin(x)     Serial.begin(x)
  #define debug1_sprintln(x)  Serial.println(x)
  #define debug1_sprint(x)    Serial.print(x)
  #define debug1_vprintln(x)  Serial.println(x)
  #define debug1_vprint(x)    Serial.print(x)
#else
  #define debug1_sprintln(x)
  #define debug1_sprint(x)
  #define debug1_vprintln(x)
  #define debug1_vprint(x)   
#endif

#ifdef debug2
  #define debug2_begin(x)     myDebugSerial.begin(x)
  #define debug2_sprintln(x)  myDebugSerial.println(x)
  #define debug2_sprint(x)    myDebugSerial.print(x)
  #define debug2_vprintln(x)  myDebugSerial.println(x)
  #define debug2_vprint(x)    myDebugSerial.print(x)
#else
  #define debug2_sprintln(x)
  #define debug2_sprint(x)
  #define debug2_vprintln(x)
  #define debug2_vprint(x)   
#endif

#ifdef debug3
  #define debug3_begin(x)     myDebugSerial.begin(x)
  #define debug3_sprintln(x)  myDebugSerial.println(x)
  #define debug3_sprint(x)    myDebugSerial.print(x)
  #define debug3_vprintln(x)  myDebugSerial.println(x)
  #define debug3_vprint(x)    myDebugSerial.print(x)
#else
  #define debug3_sprintln(x)
  #define debug3_sprint(x)
  #define debug3_vprintln(x)
  #define debug3_vprint(x)   
#endif

<snippet>
  <content>
 PWM Driver
    
 This is a library for
 
 MICS-VZ-86F, MICS-VZ-86T, MICS-VZ-87, MICS-VZ-89TE, MICS-VZ-89TE1
 
 Indoor Air Quality Sensor from SGX Sensortech Limited
 
 One or two PWM multiplexed output
 
 Tested with the ESP8266
 
 #include "MICS-VZ-89TE.h"
 
 MICS-VZ-86 air;
 
 void setup() {
 
  air.begin(5);// GPIO5, default, PWM multiplexed (two value)
  
  //air.begin(5, 2); // GPIO5, PWM multiplexed
  
  //air.begin(4, 1); // GPIO4, for one value
  
 }

 void loop() {
 
  delay(1000);
  
  Serial.print(" ");
  
  Serial.print(air.getVOC()); //Only for PWM multiplexed return: value (ppb) or -1 - error, VOC doesn't support for one value, -2 not connected or the divice is broken
  
  Serial.print(" ");
  
  Serial.print(air.getCO2()); //return: value co2 (ppm), or -1 - error, -2 not connected or the divice is broken
  
 }

 kulasov()gmail.com 
 
 </content>
  <tabTrigger>readme</tabTrigger>
</snippet>

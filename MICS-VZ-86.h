#ifndef __MICS_VZ_86_H__

#define __MICS_VZ_86_H__

#include "Arduino.h"

class MICS_VZ_86 {
  private:
  int co2;
  int voc;
  byte type;	
  uint8_t pin;
  float percentage(float pwm_value);
  void setValues(float proc);
  void read(void);

  public:
  MICS_VZ_86(void);
    void begin(uint8_t pin);
    void begin(uint8_t pin, byte type);
    int getCO2(void);
    int getVOC(void);    
};
#endif
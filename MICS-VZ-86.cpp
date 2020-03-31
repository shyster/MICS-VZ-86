/***************************************************************************
 
 Vladyslav Kulasov
 
 This is a arduino library for MICS-VZ-86, MICS-VZ-87, MICS-VZ-89 Indoor Air Quality Sensor.
 
***************************************************************************/

#include "MICS-VZ-86.h"

MICS_VZ_86::MICS_VZ_86(void) {
	this->voc = 0;
	this->co2 = 0;
}

void MICS_VZ_86::begin(uint8_t pin) {
  this->begin(pin, 2);
}

void MICS_VZ_86::begin(uint8_t pin, byte type) {
  pinMode(pin, INPUT_PULLUP);
  this->pin = pin;
  this->type = type;
}

int MICS_VZ_86::getCO2(void) {
	this->read();
  return this->co2;
}

int MICS_VZ_86::getVOC(void) {
	this->read();
  return this->voc;
}

void MICS_VZ_86::read(void) {
	float pwm_value1 = pulseIn(this->pin, HIGH);
        if (type == 2){ // PWM multiplexed output
		float pwm_value2 = pulseIn(this->pin, HIGH);
		float proc2 = percentage(pwm_value2);
		setValues(proc2);
	} else {
	        this->voc = -1;
	}
	float proc1 = percentage(pwm_value1);
        setValues(proc1);
}

float MICS_VZ_86::percentage(float pwm_value) {
	return pwm_value / 33300 * 100;
 }

void MICS_VZ_86::setValues(float proc) {
	if (type ==2){ // PWM multiplexed output
		if (proc < 5 & proc > 0) this->voc = 0;
		if (proc >= 5 & proc <= 45) this->voc =  (proc - 5) * (1000 / (45 - 5));
		if (proc > 45 & proc < 55) this->co2 = 400;
		if (proc >= 55 & proc <= 95) this->co2 = (proc - 55) * ((2000 - 400) / (95 - 55)) + 400;
	} else {
		if (proc >= 5 & proc <= 95) this->co2 = (proc - 5) * ((2000 - 400) / (95 - 5)) + 400;
		this->voc = -1;
	}
	if (proc > 95) {
		this->voc = -1;
		this->co2 = -1;
	}

        if (proc == 0) {
		this->voc = -2;
		this->co2 = -2;
	}
}

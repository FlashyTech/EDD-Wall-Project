#include <pigpio.h>
#include <stdio.h>

#include "pin.h"

#define RETRACTPOS 0
#define DEPLOYPOS 100

#define SPEED_MAXFWRD 100
#define SPEED_FORWARD 147
#define SPEED_NOMINAL 150
#define SPEED_BACKWARD 153
#define SPEED_MAXBKWD 200

extern int encoderPos;

void moveto(int position) {
	if (encoderPos < position){
		gpioPWM(PIN_MOTOR, SPEED_FORWARD);
		while (encoderPos < position) {
				printf(NULL);
		}
	}
	else if (encoderPos > position){
		gpioPWM(PIN_MOTOR, SPEED_BACKWARD);
		while (encoderPos > position) {
				printf(NULL);
		}
	}
	gpioPWM(PIN_MOTOR, SPEED_NOMINAL);
}

void decode(int pin, int level, uint32_t tick) {
	if (level == 1){
		char bState = gpioRead(PIN_ENCB);
		if (bState == 0)
			encoderPos++;
		if (bState == 1)
			encoderPos--;
	}
}


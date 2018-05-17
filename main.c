#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>

#include "pin.h" //pin defs
#include "sheet.h" //drives the sheet using information from encoder

int encoderPos;
int occupied;

void buttonPress(int pin, int level, uint32_t tick) {
	if (level == 1 && occupied == 0){
		occupied = 1;
		if (encoderPos <= RETRACTPOS)
			moveto(DEPLOYPOS);
		else
			moveto(RETRACTPOS);
		occupied = 0;
	}
}

int initialize() {
	if (gpioInitialise() < 0)
		return 1;

	// PWM channel for motor
	gpioSetMode(PIN_MOTOR, PI_OUTPUT);
	gpioSetPWMrange(PIN_MOTOR, 300);
	gpioSetPWMfrequency(PIN_MOTOR, 1 / 0.003);
	gpioPWM(PIN_MOTOR, SPEED_NOMINAL);

	// Encoder channel A
	gpioSetMode(PIN_ENCA, PI_INPUT);
	encoderPos = 0;

	// Encoder channel B
	gpioSetMode(PIN_ENCB, PI_INPUT);

	// Button for who knows what
	gpioSetMode(PIN_BTN, PI_INPUT);
	gpioSetPullUpDown(PIN_BTN, PI_PUD_DOWN);
	gpioSetAlertFunc(PIN_BTN, buttonPress);

	return 0;
}

int main() {
	if (initialize() == 1){
		fprintf(stderr, "Error: GPIO initialization failed");
		return EXIT_FAILURE;
	}

	for (;;) {
		while (gpioRead(PIN_BTN) == 0) {}
		
		if (encoderPos <= RETRACTPOS)
			moveto(DEPLOYPOS);
		else if (encoderPos >= DEPLOYPOS)
			moveto(RETRACTPOS);
	}
	
	return EXIT_SUCCESS;
}

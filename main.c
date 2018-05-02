#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>

#include "pin.h" //pin defs
#include "sheet.h" //drives the sheet using information from encoder

int encoderPos;

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
	gpioSetPullUpDown(PIN_ENCA, PI_PUD_DOWN);
	encoderPos = 0;
	gpioSetAlertFunc(PIN_ENCA, decode);

	// Encoder channel B
	gpioSetMode(PIN_ENCB, PI_INPUT);
	gpioSetPullUpDown(PIN_ENCB, PI_PUD_DOWN);

	// Button for who knows what
	gpioSetMode(PIN_BTN, PI_INPUT);
	gpioSetPullUpDown(PIN_BTN, PI_PUD_DOWN);

	return 0;
}

int main() {
	if (initialize() == 1){
		fprintf(stderr, "Error: GPIO initialization failed");
		return EXIT_FAILURE;
	}

	gpioPWM(PIN_MOTOR, SPEED_FORWARD);
	printf("Running motor at full forward throttle\n");
	printf("Press any key to continue: ");
	getchar();

	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <pigpio.h>

#include "pin.h" //pin defs
// #include "sheet.h" //drives the sheet using information from encoder

int initialize() {
	gpioInitialise();

	// PWM channel for motor
	gpioSetMode(PIN_MOTOR, PI_OUTPUT);
	gpioSetPWMRange(PIN_MOTOR, 300);
	gpioSetPWMFrequency(PIN_MOTOR, 1 / 0.003);

	// Encoder channel A
	gpioSetMode(PIN_ENCA, PI_INPUT);
	gpioSetPullUpDown(PIN_ENCA, PI_PUD_DOWN);
	// gpioSetAlertFunc(PIN_ENCA, decode);

	// Encoder channel B
	gpioSetMode(PIN_ENCB, PI_INPUT);
	gpioSetPullUpDown(PIN_ENCB, PI_PUD_DOWN);

	// Button for who knows what
	gpioSetMode(PIN_BTN, PI_INPUT);
	gpioSetPullUpDown(PIN_BTN, PI_PUD_DOWN);
}

int main() {
	initialize();

	gpioPWM(PIN_MOTOR, 200);
	printf("Running motor at full forward throttle\n");
	printf("Press any key to continue: ");
	getchar();
}

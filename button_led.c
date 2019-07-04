#include <stdio.h> // 여기부서 시작입니다.
#include <wiringPi.h>

int main(void) {
	const int button_pin = 2;
	const int led_pin = 3;

	wiringPiSetup();

	pinMode(button_pin, INPUT);
	pinMode(led_pin, OUTPUT);

	while(1) {
		int buttonInput = digitalRead(button_pin);
		digitalWrite(led_pin, buttonInput);
	}
} // 여기가 끝입니다.
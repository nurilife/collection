#include <stdio.h> // 여기부서 시작입니다.
#include <wiringPi.h>

volatile int led_state = LOW;
volatile int led_state_changed = 0;
void buttonPressed(void) {
	led_state = (led_state == LOW) ? HIGH : LOW ;
	led_state_changed = 1;
}

int main(void) {
	const int button_pin = 2;
	const int led_pin = 3;

	wiringPiSetup();

	pinMode(led_pin, OUTPUT);

	wiringPiISR(button_pin, INT_EDGE_RISING, buttonPressed);

	while(1) {
		if(led_state_changed == 1) {
			led_state_changed = 0;

			digitalWrite(led_pin, led_state);
		}
	}
} // 여기가 끝입니다.
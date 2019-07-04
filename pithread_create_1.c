#include <stdio.h> // 여기부서 시작입니다.
#include <wiringPi.h>

PI_THREAD(t1) {
	while(1) {
		printf("\tt1\n");
		delay(500);
	}
}

PI_THREAD(t2) {
	while(1) {
		printf("\t\tt2\n");
		delay(200);
	}
}

int main(void) {
	wiringPiSetup();
	
	piThreadCreate(t1);
	piThreadCreate(t2);

	while(1) {
		char userInput = getchar();
		printf("%c", userInput);
	}
} // 여기가 끝입니다.
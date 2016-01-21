


#include "sketch.h"



void setup(void){
	pinMode(PIN_LED1, OUTPUT);

}

void loop(void){
	digitalWrite(PIN_LED1, HIGH);
	delay(1000);
	digitalWrite(PIN_LED1, LOW);
	delay(1000);
}

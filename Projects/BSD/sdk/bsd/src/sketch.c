


#include "sketch.h"



void setup(void){
	pinMode(PIN_LED0, OUTPUT);

}

void loop(void){
	digitalWrite(PIN_LED0, HIGH);
	delay(1000);
	digitalWrite(PIN_LED0, LOW);
	delay(1000);
}

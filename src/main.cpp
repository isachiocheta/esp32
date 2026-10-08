/*#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
} */
#include <Arduino.h>
#define pino_led 2

void setup(){
   pinMode(pino_led, OUTPUT);
}

void loop(){
   digitalWrite(pino_led, HIGH);
   delay(1000);
   digitalWrite(pino_led, LOW);
   delay(1000);
}

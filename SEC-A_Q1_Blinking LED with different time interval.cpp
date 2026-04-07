// LED pins
int led1 = 2;
int led2 = 3;
int led3 = 4;

// time intervals
unsigned long interval1 = 500;
unsigned long interval2 = 1000;
unsigned long interval3 = 1500;

// store last time
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// LED states
bool state1 = LOW;
bool state2 = LOW;
bool state3 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // LED 1
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    state1 = !state1;
    digitalWrite(led1, state1);
  }

  // LED 2
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    state2 = !state2;
    digitalWrite(led2, state2);
  }

  // LED 3
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    state3 = !state3;
    digitalWrite(led3, state3);
  }
}
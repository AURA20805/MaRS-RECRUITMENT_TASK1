#include <Servo.h>

#define trig 9
#define echo 8

int redLED = 4;
int greenLED = 3;

Servo gate;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  gate.attach(6);  // servo control pin

  gate.write(0);   // gate closed initially
}

void loop() {

  // --- ultrasonic pulse ---
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // --- logic ---
  if (distance < 20 && distance > 0) {   // object detected

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    gate.write(90);   // open gate

  } else {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    gate.write(0);    // close gate
  }

  delay(100);
}
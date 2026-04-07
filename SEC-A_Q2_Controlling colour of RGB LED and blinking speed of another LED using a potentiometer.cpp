// RGB LED pins 
int redPin = 9;
int greenPin = 11;
int bluePin = 10;

// Separate blinking LED
int blinkLED = 3;

// Potentiometer input
int potPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(blinkLED, OUTPUT);

  analogWrite(redPin,   0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin,  0);
}

void loop() {
  int pot = analogRead(potPin);
  
  // Blink speed
  int speed = map(pot, 0, 1023, 50, 1000);
  
  digitalWrite(blinkLED, HIGH);
  delay(speed);
  digitalWrite(blinkLED, LOW);
  delay(speed);

  //rgb colour change
  int r, g, b;

  if (pot < 341) {
    r = map(pot, 0, 340, 255, 0);
    g = map(pot, 0, 340, 0, 255);
    b = 0;
  }
  else if (pot < 682) {
    r = 0;
    g = map(pot, 341, 681, 255, 0);
    b = map(pot, 341, 681, 0, 255);
  }
  else {
    r = map(pot, 682, 1023, 0, 255);
    g = 0;
    b = map(pot, 682, 1023, 255, 0);
  }

  analogWrite(redPin,   r);
  analogWrite(greenPin, g);
  analogWrite(bluePin,  b);
}
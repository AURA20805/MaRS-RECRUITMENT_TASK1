int ledPin = 7;
int buttonPin = 2;

unsigned long ledOnTime = 0;
unsigned long waitStartTime = 0;
unsigned long waitDuration = 0;

bool waitingForLED = true;      
bool waitingForReaction = false; 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Reaction Time Tester Ready...");
  Serial.println("Wait for LED to turn ON...");

  // Start random wait timer
  waitStartTime = millis();
  waitDuration = random(1000, 4000);   
}

void loop() {

  if (waitingForLED) {
    if (millis() - waitStartTime >= waitDuration) {
      digitalWrite(ledPin, HIGH);       // LED turns ON
      ledOnTime = millis();             // Start timing
      waitingForLED = false;
      waitingForReaction = true;

      Serial.println("LED ON! Press the button!");
    }
  }

  if (waitingForReaction) {
    if (digitalRead(buttonPin) == LOW) {  // button pressed
      unsigned long reactionTime = millis() - ledOnTime;

      digitalWrite(ledPin, LOW);

      Serial.print("Your reaction time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      Serial.println("Preparing next test...");
      Serial.println();

      // Reset for next test
      waitingForLED = true;
      waitingForReaction = false;
      waitStartTime = millis();
      waitDuration = random(1000, 4000);   // new random delay
    }
  }
}
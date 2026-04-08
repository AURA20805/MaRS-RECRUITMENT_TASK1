void setup(){
  pinMode(A5, INPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int val= analogRead(A5);
  Serial.print("soil moisture value: ");
  Serial.print(val);
  
  if (val>500){
    digitalWrite(11,LOW);
    Serial.println("MOTOR/LED: OFF (Soil is dry)");
  }
  else{
    digitalWrite(11,HIGH);
    Serial.println("MOTOR/LED: ON (Soil is moist)");
  }
  delay(1000);
}
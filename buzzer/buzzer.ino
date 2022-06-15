const int buzzer = 9;
void setup() {
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  tone(buzzer, 5000); 
  delay(10000);        
  noTone(buzzer);     
  delay(10000); 
  

}

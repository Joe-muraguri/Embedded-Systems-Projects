const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);  

}

void loop() {
  long duration,inches,cm;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin ,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println();
  delay(1000);
}
long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
  }
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
  }  

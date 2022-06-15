int redLED = PA6;
int greenLED = PA7;
int blueLED = PA8;
void setup() {
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
}
void setColor(int redValue,int greenValue,int blueValue){
    analogWrite(redLED,255-redValue);
    analogWrite(greenLED,255-greenValue);
    analogWrite(blueLED,255-blueValue);
  }

void loop() {
  setColor(255,0,0);
  delay(500);

  setColor(0,255,0);
  delay(500);

  setColor(0,0,255);
  delay(500);

  setColor(255,255,0);
  delay(500);

  setColor(200,40,145);
  delay(500);

  setColor(0,255,255);
  delay(500);

  setColor(255,0,255);
  delay(500);

  setColor(255,255,255);
  delay(500);

}

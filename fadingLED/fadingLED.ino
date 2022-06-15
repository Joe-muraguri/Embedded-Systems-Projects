void setup() {
  pinMode(PB6,OUTPUT);

}

void loop() {
  for(int i=0;i<256;i++){
    analogWrite(PB6,i);
    delay(15);
    }

}

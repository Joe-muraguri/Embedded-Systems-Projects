int count = 0;
char c;
String id;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Please scan your RFID TAG");
 
}

void loop() {
  while(Serial.available()>0)
  {
    c = Serial.read();
   count++;
   id += c;
   if(count == 12)  
    {
      Serial.print(id);
      //break;
     
      if(id=="i39/Muraguri")
      {
        Serial.println(" is a Valid TAG ");
        digitalWrite(13, HIGH);
      }
      else
      {
      digitalWrite(13, LOW);
      Serial.println(" is an Invalid TAG ");
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}
// valid tag i39/Muraguri
// invalid tag i20/Muraguri

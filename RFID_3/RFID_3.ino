int count = 0;
char c;
String id;
String Name;
String Reg_Number;

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
     
      if(id=="AB123456789A")
      {
        Name = "Joe Muraguri";
        Reg_Number = "i39/86204/2017";
        Serial.println("Valid TAG");
        Serial.print(Name);
        Serial.print("    ");
        Serial.print(Reg_Number);
        Serial.print("    ");
        Serial.print("10:45 AM");
        digitalWrite(13, HIGH);
      }
      else if (id=="AB123456789B")
      {
        Name = "SAMSON EKENO";
        Reg_Number = "i39/1883/2018";
        Serial.println("Valid TAG");
        Serial.print(Name);
        Serial.print("    ");
        Serial.print(Reg_Number);
        Serial.print("    ");
        Serial.print("10:50 AM");
        digitalWrite(13, HIGH);
        
        }
      
      else
      {
      digitalWrite(13, LOW);
      Serial.println("Invalid TAG");
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}

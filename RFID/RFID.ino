#include <SPI.h>
#include <MFRC522.h>
#include <RFID.h>
#include <TimeLib.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);
MFRC522 mfrc522(SS_PIN, RST_PIN);

String rfidCard;
String Name;
String Reg_Number;
int Number;
void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.init();
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.println(" Student Name |  Registration Number   | Date/Time ");
}
void printTime() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(",");
}

void loop() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      //Serial.println(rfidCard);
      
      Serial.println("");
      if (rfidCard == "246 179 152 53"){
        Name = "Joe Muraguri";
        Reg_Number = "i39/86204/2017";
        digitalWrite(5,HIGH);
        digitalWrite(8,HIGH);
        delay(300);
        digitalWrite(8,LOW);
        delay(300);
        digitalWrite(8,HIGH);
        delay(300);
        digitalWrite(8,LOW);
        delay(300);
        digitalWrite(5,LOW);
        Serial.print(Name);
        Serial.print("    ");
        Serial.print(Reg_Number);
        Serial.println();
        
        }
      else{
        digitalWrite(6,HIGH);
        digitalWrite(8,HIGH);
        delay(2000);
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);
        Serial.print("Card Not Recognised");
        }
    }
    rfid.halt();
  }
}

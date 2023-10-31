#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX
char myChar ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hola Mundo");

  mySerial.begin(9600);
  mySerial.println("Hello world");
} 

void loop() {
  while(mySerial.available()){
    myChar = mySerial.read();
    Serial.println(myChar);
  }

   while(Serial.available()){
    myChar = Serial.read();
    mySerial.print(myChar);
  }
}

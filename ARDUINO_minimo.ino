#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX ->  Solo en caso de querer conectarlos en otros pines
char myChar ;

//Es necesario desconectar el bluethot al momento de cargar el programa en el arduino ya que este interfiere 
// Bluethoot
// Tx = 0
// Rx = 1

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  // Prueba bluetooth
  mySerial.begin(9600);
  mySerial.println("Hello world");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()){
    myChar = mySerial.read();
    Serial.println(myChar);
    if (myChar == 'a') {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
    } else {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
    }
  }
}

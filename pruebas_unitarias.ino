#include <Servo.h> 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX ->  Solo en caso de querer conectarlos en otros pines
char myChar ;

//Es necesario desconectar el bluethot al momento de cargar el programa en el arduino ya que este interfiere 
// Bluethoot
// Tx = 0
// Rx = 1

//Servomotores

Servo Servo1;  
Servo Servo2;  
int angulo1;
int angulo2;

 // Puente H
int in1_m1 = 4;
int in2_m1 = 5;
int in3_m2 = 6;
int in4_m2 = 7;

//Ultrasonico
int trigPin = 8;
int echoPin = 9;

//Infrarrojos
int Infra1 = 10;
int Infra2 = 11;

// Sonido
int Buz = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hola Mundo");

  mySerial.begin(9600);
  mySerial.println("Hello world");
  

  Servo1.attach(2);  // asignamos el pin 3 al servo.
  Servo2.attach(3);  // asignamos el pin 3 al servo.
  
 pinMode (in1_m1,OUTPUT);
 pinMode (in2_m1,OUTPUT);
 pinMode (in3_m2,OUTPUT);
 pinMode (in4_m2,OUTPUT);

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(trigPin, LOW);

 pinMode(Infra1, INPUT);
 pinMode(Infra2, INPUT);

 pinMode(Buz, OUTPUT);

}

void loop() {
int dist;


  // PRUEBAS UNITARIAS

  // Motores y Servos 
  //adelante();
  //delay(1000);
  //para();
  //M1.write(90);


  // Antes de continuar realizar prueba emisión recepción BLE_Test
  
  // Prueba Ultrasónico
  //dist = myUltra();
  //Serial.println(dist);
  //mySerial.println(dist); // Esta línea se activa cuando ya se haya probado la conexión BLE
  

}



void adelante () { //Atras
digitalWrite(in1_m1, HIGH); 
digitalWrite(in2_m1, LOW);
digitalWrite(in3_m2, LOW); 
digitalWrite(in4_m2, HIGH);
}

 void atras () { //Atras
digitalWrite(in1_m1, LOW); 
digitalWrite(in2_m1, HIGH);
digitalWrite(in3_m2, HIGH); 
digitalWrite(in4_m2, LOW);
 }
 
void izq () { //IZQ
digitalWrite(in1_m1, HIGH); 
digitalWrite(in2_m1, LOW);
digitalWrite(in3_m2, HIGH); 
digitalWrite(in4_m2, LOW);
}

void der () { //Atras
digitalWrite(in1_m1, LOW); 
digitalWrite(in2_m1, HIGH);
digitalWrite(in3_m2, LOW); 
digitalWrite(in4_m2, HIGH);
}

void para () { //Atras
digitalWrite(in1_m1, LOW); 
digitalWrite(in2_m1, LOW);
digitalWrite(in3_m2, LOW); 
digitalWrite(in4_m2, LOW);
}

void brazo (){
angulo1= 0;
  angulo2= 180;
  Servo1.write(angulo1);
  Servo2.write(angulo2);
  delay(1000);  

  angulo1= 90;
  angulo2= 90;
  Servo1.write(angulo1);
  Servo2.write(angulo2);
  delay(1000); 

}


int myUltra() {
  int duration;
  double cm;
   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  //inches = (duration/2) / 74; 
  
  return cm;  
}

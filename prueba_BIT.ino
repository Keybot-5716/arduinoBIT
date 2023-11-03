#include <Servo.h> 
//Es necesario desconectar el bluethot al momento de cargar el programa en el arduino ya que este interfiere 
// Bluethoot
// Tx = 0
// Rx = 1

//Servomotores

Servo M1;  
Servo M2;  
int angulo1;
int angulo2;

 // Puente H
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;

//Ultrasonico
int Trigger = 8;
int Echo = 9;

//Infrarrojos
int S1 = 10;
int S2 = 11;

// Sonido
int Buz = 12;

void setup() {
  Serial.begin(9600); // iniciamos el puerto serial
  M1.attach(2);  // asignamos el pin 3 al servo.
  M2.attach(3);  // asignamos el pin 3 al servo.
  
 pinMode (in1,OUTPUT);
 pinMode (in2,OUTPUT);
 pinMode (in3,OUTPUT);
 pinMode (in4,OUTPUT);

 pinMode(Trigger, OUTPUT);
 pinMode(Echo, INPUT);
 digitalWrite(Trigger, LOW);

 pinMode(S1, INPUT);
 pinMode(S2, INPUT);

 pinMode(Buz, OUTPUT);

}

void loop() {
  M1.write(90);
  M2.write(90);
  delay(1000);
 
adelante();
delay (1000);
para();
  M1.write(0);
  M2.write(180);
  delay(1000);
  M1.write(90);
  M2.write(90);
  delay(1000);
atras();
delay (1000);
para();
  M1.write(90);
  M2.write(180);
  delay(1000);
izq();
delay (1000);
para();
  M1.write(0);
  M2.write(90);
  delay(1000);
  para();
der();
delay (1000);
para();
delay(500);

}

void adelante () { //Atras
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
}

 void atras () { //Atras
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
 }
 
void izq () { //IZQ
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
}

void der () { //Atras
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
}

void para () { //Atras
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);
}

void brazo (){
angulo1= 0;
  angulo2= 180;
  M1.write(angulo1);
  M2.write(angulo2);
  delay(1000);  

  angulo1= 90;
  angulo2= 90;
  M1.write(angulo1);
  M2.write(angulo2);
  delay(1000); 

}

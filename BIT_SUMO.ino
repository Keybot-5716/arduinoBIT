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
const int Trigger = 8;   //Pin digital 2 para el Trigger del sensor
const int Echo = 9;   //Pin digital 3 para el echo del sensor

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

//Infrarrojos
int S1 = 10;
int S2 = 11;

// Sonido
int Buz = 12;

void setup() {
  Serial.begin(9600); // iniciamos el puerto serial

  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  
  M1.attach(2);  // asignamos el pin 3 al servo.
  M2.attach(3);  // asignamos el pin 3 al servo.
  
 pinMode (in1,OUTPUT);
 pinMode (in2,OUTPUT);
 pinMode (in3,OUTPUT);
 pinMode (in4,OUTPUT);

 pinMode(S1, INPUT);
 pinMode(S2, INPUT);

 pinMode(Buz, OUTPUT);

}

void loop() {
  
  ultrasonico();
  if(d == 20){
    adelante();
  }
  else{
    der();
  }
  

}// termina void loop

void ultrasonico(){

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
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

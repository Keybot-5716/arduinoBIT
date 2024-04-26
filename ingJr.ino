/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/


const int trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int echo = 3;   //Pin digital 3 para el Echo del sensort
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(11, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT);


  pinMode(trigger, OUTPUT); //pin como salida
  pinMode(echo, INPUT);  //pin como entrada
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int bot = digitalRead(12);

  int dis = ultra();
  delay(100);
  if (bot == LOW || dis < 6) // Si se presiona
  {
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else {
    digitalWrite(11, LOW);
    digitalWrite(13,LOW);
  }

 
  
}

int ultra()
{
  float tiempo_de_espera,distancia; 
digitalWrite (trigger,LOW); // ponemos en bajo el pin 8 durante 2 microsegundos
delayMicroseconds(2);
digitalWrite (trigger, HIGH);// ahora ponemos en alto pin 8 durante 10 microsegundos;
delayMicroseconds (10);     // pues este el momento en que emite el sonido durante 10 segungos
digitalWrite (trigger, LOW); // ahora ponemos en bajo pin 8 
tiempo_de_espera = pulseIn (echo,HIGH); // pulseIn, recoge la señal del sonido que emite el trigger
/*La función pulseIn espera la aparición de un pulso en una entrada y mide su duración, dando como resultado la duración medida                   
 El primer parámetro (ECHO) es el pin sobre el que se realizará la medición.
Y el segundo parámetro (HIGH) indica si el pulso a esperar será un 1 (HIGH) o un 0 (LOW).
 */
distancia =(tiempo_de_espera/2)/29.15; // formula para hallar la distancia
Serial.print (distancia);    // imprimimos la distancia en cm
Serial.println ("cm");
delay (1000);
  return distancia;
}

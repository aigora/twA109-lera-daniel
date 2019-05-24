#include <SoftwareSerial.h>
SoftwareSerial BT(2,3); 

const int EchoPin1 = 6;
const int TriggerPin1 = 7;

const int EchoPin2 = 8;
const int TriggerPin2 = 9;

int ENA = 5;
int IN1 = 10;
int IN2 = 11;


int ENB = 4;
int IN3 = 12;
int IN4 = 13;



void setup()
{
  BT.begin(9600) ;

  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  pinMode(TriggerPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  pinMode(TriggerPin2, OUTPUT);
  pinMode(EchoPin2, INPUT);
}

void loop()
{
  int c1, c2 ;
  char aux;
  c1 = Calculo_Distancia(TriggerPin1, EchoPin1);
  c2 = Calculo_Distancia(TriggerPin2, EchoPin2);
      delay(20);
  if(c1<20 || c2<20)
    Paro();
  
  aux = BT.read();


 switch (aux)
 {
 case 'A':
 Avance();
 break;
 case 'R':
 Retroceso();
 break;
 case 'D':
 Giro_Derecha();
 break;
 case 'I':
 Giro_Izquierda();
 break;
 case 'P':
 Paro();
 break;
 }
     }

 
 
      
        


void Avance ()
{

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 200); 

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 200); 
}

void Retroceso ()
{
 
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 200);  

  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 200); 
}

void Giro_Derecha ()
{

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 150); 

  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); 
}

void Giro_Izquierda ()
{

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); 
  
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 150); 
}

void Paro ()
{

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); 

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); 
}

int Calculo_Distancia(int TriggerPin, int EchoPin) {
   
   long tiempo, cm;
   
   digitalWrite(TriggerPin, LOW); 
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   tiempo = pulseIn(EchoPin, HIGH);  
   
   cm = tiempo * 10 / 292/ 2;  
   return cm;
}

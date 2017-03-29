#include <dht.h>

#define ENA 5
#define ENB 9
#define fan1 6
#define fan2 7
#define coil1 8
#define coil2 12
#include <dht.h>
#include<SoftwareSerial.h>//for bt communicn
SoftwareSerial BT(10,11); // 10 rx and 11 tx
dht DHT;
#define DHT11 2// data pin
char c[100];

void setup() {
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);

  Serial.begin(9600);//start commn at baud 9600
  BT.begin(9600);//BT communication
  Serial.println("SOCHWARE MUSHROOM AUTOMATION");
  delay(5000);
}

void loop() {
  // fan();
  int chk = DHT.read11(DHT11);
  delay(10);
  BT.print(DHT.humidity,1);
  BT.print(",");
  BT.print(DHT.temperature,1);
  BT.print(";");
  Serial.println("Sochware Humidity and temperature controller");
  Serial.println(" Humidity " );
  Serial.println(DHT.humidity);
  Serial.println(" Temparature ");
  Serial.println(DHT.temperature, 1);




  if (DHT.temperature>=25)
  {
    fan();//RUN A FAN

  }
  else if(DHT.temperature<=20)
  {
    coil();
  }
  delay(2000);

}

void fan()
{
  digitalWrite(fan1,HIGH);
  digitalWrite(fan2,LOW);
  digitalWrite(coil1,LOW);
  digitalWrite(coil2,LOW);
  BT.print("/n Fan running /n");
  Serial.println("Fan running");

}

void coil()
{
  digitalWrite(fan1,HIGH);
  digitalWrite(fan2,LOW);
  digitalWrite(coil1,HIGH);
  digitalWrite(coil2,LOW);
  BT.print("/n Heating action /n");
  Serial.println("Heater running");


}
/*
//in case if hairDrier is used
void fan()
{digitalWrite(fan1,1);
}
void coil()
{digitalWrite(coil1,1);
}*/







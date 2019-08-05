/*DISTANCE CALCULATOR*/ 

/*
BY:
NAMAN JINDAL-16CSU223
NIKHIL YADAV-16CSU228
PALAK KHURANA-16CSU237
PIYUSH KATARYA-16CSU246
*/

#include <SoftwareSerial.h>
#define trigPin 13
#define echoPin 12
#define led1 2
#define buzzer 3

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);//setting the sensor
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
 
  long DURATION, DISTANCE;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // for delay
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  DURATION = pulseIn(echoPin, HIGH);
  DISTANCE = (DURATION / 2) / 29.1;

  if (DISTANCE < 20)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(buzzer, LOW);

  }

  if (DISTANCE >= 200 || DISTANCE <= 0) {
    Serial.println("NOT IN RANGE");
  }
  else
  {
    Serial.print(DISTANCE);
    Serial.println(" cm");
  }
}




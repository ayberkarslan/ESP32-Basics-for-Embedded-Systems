#include <Arduino.h>
#include <ESP32Servo.h>

const int MOTOR_PIN = 13;
const int POT_PIN = 34;
const int ledPin = 2;
unsigned long simdikiZaman;
unsigned long oncekiZaman=0;
const long aralik=1000;
int ledDurum= LOW;
Servo motor1;
void setup() {

    motor1.attach(MOTOR_PIN);
pinMode(POT_PIN,INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {


    simdikiZaman = millis();

    if (simdikiZaman-oncekiZaman>aralik) {
        ledDurum = !ledDurum;
digitalWrite(ledPin,ledDurum);
     oncekiZaman=simdikiZaman;

    }

    long toplam=0;
for (int j=0;j<10;j++) {
    toplam= toplam + analogRead(POT_PIN);
    delay(2);
}
int ortalama = toplam/10;
    ortalama= map(ortalama,0,4095,0,180);
    motor1.write(ortalama);
    delay(10);
}

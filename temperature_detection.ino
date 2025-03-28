#include "DHT.h"



#define DHTPIN 6       // DHT11 sensor connected to pin D6

#define DHTTYPE DHT11  



#define GREEN_LED 2    // Green LED on D2

#define YELLOW_LED 3   // Yellow LED on D3

#define RED_LED 4      // Red LED on D4

#define BUZZER 5       // Buzzer on D5



DHT dht(DHTPIN, DHTTYPE);



void setup() {

    pinMode(GREEN_LED, OUTPUT);

    pinMode(YELLOW_LED, OUTPUT);

    pinMode(RED_LED, OUTPUT);

    pinMode(BUZZER, OUTPUT);

    

    dht.begin();

}



void loop() {

    float temp = dht.readTemperature(); // Read temperature

    

    if (temp < 25) {

        digitalWrite(GREEN_LED, HIGH);

        digitalWrite(YELLOW_LED, LOW);

        digitalWrite(RED_LED, LOW);

        digitalWrite(BUZZER, LOW);  // No buzzer sound

    } 

    else if (temp >= 25 && temp < 30) {

        digitalWrite(GREEN_LED, LOW);

        digitalWrite(YELLOW_LED, HIGH);

        digitalWrite(RED_LED, LOW);

        digitalWrite(BUZZER, LOW);  // No buzzer sound

    } 

    else if (temp >= 30) {

        digitalWrite(GREEN_LED, LOW);

        digitalWrite(YELLOW_LED, LOW);

        digitalWrite(RED_LED, HIGH);  // Red LED ON

        // Buzzer controlled by AND gate

    }



    delay(2000);  // Wait for 2 seconds before the next reading

}
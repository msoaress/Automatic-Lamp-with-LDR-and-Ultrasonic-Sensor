#include <Arduino.h>
#include <NewPing.h>
#include <gp_io.cpp>

int TRIGGER_PIN = 9;
int ECHO_PIN    = 10;
int MAX_DISTANCE = 100;
int ldr = A3;  //pino no qual o sensor esta conectado
int valorldr = 0;  //variavel apra armazenar a leitura do sensor

NewPing sensor( TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
gp_io out_di;



void setup() {
    out_di.setgp_io(8);
    pinMode(out_di.getgp_io(),OUTPUT);
    pinMode(ldr, INPUT);  //define o sensor como uma entrada
    digitalWrite(out_di.getgp_io(), out_di.nivel_bai);


    Serial.begin(9600);
// write your initialization code here
}

void loop() {

    int distancia = sensor.ping_cm();
    valorldr = analogRead(ldr);  //leitura do sensor
    delay(250);



    if(distancia >60 ) {

        digitalWrite(out_di.getgp_io(), out_di.nivel_alt);
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.println("\n");


    } else if (valorldr < 20) {
        digitalWrite(out_di.getgp_io(), out_di.nivel_alt);
        Serial.print("luminosidade: ");
        Serial.print(valorldr);
        Serial.println("\n");


    }    else {
        digitalWrite(out_di.getgp_io(), out_di.nivel_bai);
    }

}

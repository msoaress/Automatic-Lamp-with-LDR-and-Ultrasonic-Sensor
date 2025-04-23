#include <Arduino.h>  // importação de biblioteca padrão do arduino
#include <NewPing.h>  // importação de biblioteca padrão newping
#include <gp_io.cpp>  // importação da classe gp_io

int TRIGGER_PIN = 9; // gpio 9
int ECHO_PIN    = 10;  // gpio 10
int MAX_DISTANCE = 100; // define o range do sensor ultrasônico
int ldr = A3;  //pino no qual o sensor esta conectado
int valorldr = 0;  //variavel para armazenar a leitura do sensor

NewPing sensor( TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);   // cria uma nova instância da classe newping

// criar uma nova instãncia de um objeto
gp_io out_di;



void setup() {   // configuraçãoes


    out_di.setgp_io(8); // define qual pino digital sera usado, nesse caso o 8
    pinMode(out_di.getgp_io(),OUTPUT); // defini o pino 8 como saida
    pinMode(ldr, INPUT);  //define o sensor como uma entrada
    digitalWrite(out_di.getgp_io(), out_di.nivel_bai); // inicializa o rele em nivel baixo


    Serial.begin(9600); // defini a freqência da comunicação serial

}

void loop() {

    delay(1250);  // esse delay para a execução do codigo nessa exata instrução por 1.250 segundos

    int distancia = sensor.ping_cm(); // leitura da distância do objeto em centímetros
    valorldr = analogRead(ldr);  //leitura do sensor ldr




    if(distancia >60 ) { // se a distância for maior que 60 o bloco abaixo será executado

        digitalWrite(out_di.getgp_io(), out_di.nivel_alt);   // coloca out_di em nivel alto, ligando a lampada


        // impressão via monitor serial para simples conferência e teste .
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.println("\n");


    } else if (valorldr < 20) { // se a luminosidade for menor que 20 o bloco abaixo sera executado


        digitalWrite(out_di.getgp_io(), out_di.nivel_alt); // coloca out_di em nivel alto, ligando a lampada

        // impressão via monitor serial para simples conferência e teste .
        Serial.print("luminosidade: ");
        Serial.print(valorldr);
        Serial.println("\n");


    }    else {  // se todas as condições acima não forem satisfeitas esse bloco sera executado


        digitalWrite(out_di.getgp_io(), out_di.nivel_bai);   /* coloca out_di em nivel baixo, desligando a lampada
            ou a mantendo desligada  */
    }

}
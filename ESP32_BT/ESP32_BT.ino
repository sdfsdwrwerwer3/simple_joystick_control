// https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller

#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;

#define axisx 5 // Eixo X
#define axisy 6 // Eixo Y
#define horn 7  // Sirene

#define maxValue 255
#define minValue 0
#define stoped 125
#define deadZone 15

void setup()
{
    pinMode(axisx, OUTPUT);
    pinMode(axisy, OUTPUT);
    pinMode(horn, OUTPUT);
    Serial.begin(9600);      // inicia a comunicação serial
    ESP_BT.begin("ThetaBT"); // Bluetooth device name
    Serial.println("Iniciando...");
}

void loop()
{
    if (ESP_BT.available())
    {                                         // se receber dados via bluetooth
        String comando = ESP_BT.readString(); // le os dados
        //Serial.println(comando);              // mostra no monitor serial

        uint16_t vel = 50;
        uint16_t vel_pos = map(veldeadZone, 0, 100, stoped+deadZone, maxValue);
        uint16_t vel_neg = map(vel, 0, 100, minValue, stoped-deadZone);

        //deslocamento
        if (comando == "F")
        {
            analogWrite(axisx, stoped);
            analogWrite(axisy, vel_pos);
        }
        else if (comando == "B")
        {
            analogWrite(axisx, stoped);
            analogWrite(axisy, vel_neg);
        }
        else if (comando == "L")
        {
            analogWrite(axisx, vel_neg);
            analogWrite(axisy, stoped);
        }
        else if (comando == "R")
        {
            analogWrite(axisx, vel_pos);
            analogWrite(axisy, stoped);
        }
        else if (comando == "S" && comando == "D")
        {
            analogWrite(axisx, stoped);
            analogWrite(axisy, stoped);
        }

        // Buzina
        else if (comando == "V")
        {
            digitalWrite(horn, HIGH);
        }
        else if (comando == "v")
        {
            digitalWrite(horn, LOW);
        }

        // Velocidade
        else if (comando == "0")
        {
            vel=0;
        }
        else if (comando == "1")
        {
            vel = 10;
        }
        else if (comando == "2")
        {
            vel = 20;
        }
        else if (comando == "3")
        {
            vel = 30;
        }
        else if (comando == "4")
        {
            vel = 40;
        }
        else if (comando == "5")
        {
            vel = 50;
        }
        else if (comando == "6")
        {
            vel = 60;
        }
        else if (comando == "7")
        {
            vel = 70;
        }
        else if (comando == "8")
        {
            vel = 80;
        }
        else if (comando == "9")
        {
            vel = 90;
        }
        else if (comando == "q")
        {
            vel = 100;
        }
        
    }
}
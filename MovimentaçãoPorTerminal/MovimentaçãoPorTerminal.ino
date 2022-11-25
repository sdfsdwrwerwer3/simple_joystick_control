#include<stdbool.h>


#define axisx 5 // Eixo X
#define axisy 6 // Eixo Y

#define maxValue 255
#define minValue 0 
#define stoped 127
#define increment 5 // Define a velocidade de incremento do PWM

void setup()
{
    pinMode(axisx, OUTPUT);
    pinMode(axisy, OUTPUT);

    Serial.begin(115200);
}

void loop()
{   
    bool comPortConnected = false;

    while (!comPortConnected)
    {
        if (Serial.available() > 0) //fica esperando a conexão com o monitor serial para prosseguir com o código
        {
            comPortConnected = true;
        }
    }

    analogWrite(axisx, stoped);
    analogWrite(axisy, stoped);

    serial.print("Conectado ao COM Port\n");
    serial.print("Simulando movimento positivo do joystick para X ate %d e Y parado em %d\n", maxValue, stoped);

    for (int i = stoped; i <= maxValue; i+=increment)
    {
        analogWrite(axisx, i);
        serial.print("X: %d\n", i);
    }

    delay(100);

    serial.print("Simulando movimento negativo do joystick para X ate %d e Y parado em %d\n", minValue, stoped);

    for (int i = stoped; i >= minValue; i-=increment)
    {
        analogWrite(axisx, i);
        serial.print("X: %d\n", i);
    }

    delay(100);

    analogWrite(axisx, stoped);

    serial.print("Simulando movimento positivo do joystick para Y ate %d e X parado em %d\n", maxValue, stoped);

    for (int i = stoped; i <= maxValue; i+=increment)
    {
        analogWrite(axisy, i);
        serial.print("Y: %d\n", i);
    }

    delay(100);

    serial.print("Simulando movimento negativo do joystick para Y ate %d e X parado em %d\n", minValue, stoped);

    for (int i = stoped; i >= minValue; i-=increment)
    {
        analogWrite(axisy, i);
        serial.print("Y: %d\n", i);
    }
}
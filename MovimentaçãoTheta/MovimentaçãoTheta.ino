#include <stdlib.h> // biblioteca para incluir as variáveis com definição de tamanho em bits

#define axisx 3      // Eixo X
#define axisy 6      // Eixo Y

#define minValue 140  // Valor Mínimo dos eixos
#define maxValue 140 // Valor Máximo dos eixos

void setup() {
  Serial.begin(9600);
  pinMode(axisx, OUTPUT);
  pinMode(axisy, OUTPUT);
}

void loop() {
  analogWrite(axisx, minValue);
  analogWrite(axisy, maxValue);

}
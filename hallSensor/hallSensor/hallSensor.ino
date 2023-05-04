const int hallA = 2;
const int hallB = 3;

unsigned long lastPulseA = 0;
unsigned long lastPulseB = 0;
unsigned long timeDiff = 0;

void setup() {
  pinMode(hallA, INPUT);
  pinMode(hallB, INPUT);
  Serial.begin(9600);
}

void loop() {
  // check for a pulse on Hall A
  if (digitalRead(hallA) == HIGH && lastPulseA == 0) {
    lastPulseA = millis();  // record the time of the pulse 
    if (lastPulseB != 0) {
      timeDiff = lastPulseA - lastPulseB;  // calculate the time difference between the two pulses
      Serial.println("Time diff B->A: " + String(timeDiff) + " ms");
      lastPulseA = 0;  // reset the pulse marker
      lastPulseB = 0;
    }
  }
  // check for a pulse on Hall B
  if (digitalRead(hallB) == HIGH && lastPulseB == 0) {
    lastPulseB = millis(); 
    if (lastPulseA != 0) {
      timeDiff = lastPulseB - lastPulseA;
      Serial.println("Time diff A->B: " + String(timeDiff) + " ms");
      lastPulseA = 0;  
      lastPulseB = 0;
    }
  }
}

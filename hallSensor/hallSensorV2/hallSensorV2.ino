const int hallA = 2;
const int hallB = 3;

unsigned long lastPulseA = 0;  // pulse marker
unsigned long lastPulseB = 0;
unsigned long timeDiff = 0;

void setup() {
  pinMode(hallA, INPUT);
  pinMode(hallB, INPUT);
  attachInterrupt(digitalPinToInterrupt(hallA), hallDetecA, RISING);  // call void hallDetecA if detect rising edge
  attachInterrupt(digitalPinToInterrupt(hallB), hallDetecB, RISING);  // can use only with pin 2 and 3 on uno R3
  Serial.begin(9600);
}

void loop() {
  // do nothing here
}

void hallDetecA() {
  if (lastPulseB == 0) {
    lastPulseA = millis();  // record the time of the pulse on A
  } else {
    timeDiff = millis() - lastPulseB;  // calculate the time difference between the two pulses
    Serial.println("Time diff B->A: " + String(timeDiff) + " ms");
    lastPulseA = 0;  // reset the pulse marker
    lastPulseB = 0;
  }
}

void hallDetecB() {
  if (lastPulseA == 0) {
    lastPulseB = millis();
  } else {
    timeDiff = millis() - lastPulseA;
    Serial.println("Time diff A->B: " + String(timeDiff) + " ms");
    lastPulseA = 0;
    lastPulseB = 0;
  }
}

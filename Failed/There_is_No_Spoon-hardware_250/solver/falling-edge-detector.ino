void setup() {
    Serial.begin(9600);

    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), printA, FALLING);

    pinMode(3, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(3), printB, FALLING);
}

void printA() {
    Serial.println("A");
}

void printB() {
    Serial.println("B");
}

void loop() {
}

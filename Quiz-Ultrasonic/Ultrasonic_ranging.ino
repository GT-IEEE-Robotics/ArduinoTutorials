const int TrigPin = 2;
const int EchoPin = 3;
float cm;

void setup() {
    // Serial.begin(9600);
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
}

void loop() {
    cm = readUltrasonicSensor();
    if (cm < /* INSERT VALUE */) {
        blinkClosest();
    } else {
        blinkFarthest();
    }
}

float readUltrasonicSensor() {
    
}

void blinkFarthest() {

}

void blinkClosest() {

}


#include <IRremote.h>

const int irReceiverPin = 2;
IRrecv irrecv(irReceiverPin);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("IR_Code: ");
    Serial.print(results.value, HEX);
    irrecv.resume();
  }
  delay(600);
}

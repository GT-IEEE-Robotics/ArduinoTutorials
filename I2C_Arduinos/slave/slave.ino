/*
 * slave.ino
 * Binit Shah
 * 
 * The slave device in the I2C communication receives data from the master device.
 */

#include <Wire.h>

void setup() {
    Serial.begin(9600);
    Wire.begin(9);
    Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
    Serial.print("Receiving: ");
    char msg[100];
    int msg_index = 0;
    while(Wire.available()) {
        msg[msg_index] = Wire.read();
        msg_index++;
    }
    msg[msg_index] = '\0';
    String msg_str(msg);
    Serial.println(msg_str);
}

void loop() {
}

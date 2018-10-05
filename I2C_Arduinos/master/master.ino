/*
 * master.ino
 * Binit Shah
 * 
 * The master device in the I2C communication transmits data to the slave devices.
 */

#include <Wire.h>

void setup() {
    Serial.begin(9600);
    Wire.begin();
}

void loop() {
    if (Serial.available() > 0) {
        String msg_str = Serial.readString();
        char* msg_ptr = msg_str.c_str();
        Wire.beginTransmission(9);
        Wire.write(msg_ptr, msg_str.length());
        Wire.endTransmission();
        Serial.println("Sending: " + msg_str);
    }
}

/* pin defintions */
#define ENC_A (2)   // encoder input A
#define ENC_B (3)   // encoder input B

volatile int32_t count = 0;   // encoder step count, 32 bit volatile integer (volatile ensures the value is fetched everytime, necessary for global variables modified by interrupt handlers)
const int8_t encoder_table[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // attach the encoder interrupt function to changes on both encoder input pins
    attachInterrupt(digitalPinToInterrupt(ENC_A), encoder_isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC_B), encoder_isr, CHANGE);
}

void loop() {
    // the loop function has nothing to do with regards to the encoder readings
    // it only blinks the LED and prints out the count to prove everything is working

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
    
    // when accessing the encoder count, prevent interrupts from modifying the variable
    noInterrupts();
    Serial.println(count);
    interrupts();
}

// encoder interrupt function, fires on change of either encoder input signal
// see tutorial/gif for description about how this function works
void encoder_isr() {
    static uint8_t enc_val = 0; // static allows this value to persist across function calls

    enc_val = enc_val << 2; // shift the previous state to the left
    enc_val = enc_val | ((PIND & 0b1100) >> 2); // or the current state into the 2 rightmost bits

    count += encoder_table[enc_val & 0b1111];    // preform the table lookup and increment count accordingly
}

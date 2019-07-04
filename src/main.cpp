
#include "config.h"

double adVal = 0.0;
char sendStr[30] = "";
String readString = "";
int outT = 0;
int data[DATA_LEN] = {1, 0, 0, 1, 1, 1, 0, 1};

void timer2ISR(){
    auto carrier = sin(2 * PI * 0.01 * (outT++));
    duguAnalogWrite((uint16)(carrier * data[0]));
}

void setup() {
    Serial1.begin(SERIAL_BAUD);
    Serial1.println("Hello Magnetic Communication STM32F103VET6!");

    Timer2.setPeriod(TIMER_MS * 1000);
    Timer2.attachInterrupt(1, timer2ISR);

    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);
}

void loop() {
    delay(20);
    adVal = analogRead(PIN_AD); 
    sprintf(sendStr, "C1:%.2f\r\nC2:%.2f\r\nC3:%.2f\r\n", adVal, adVal, ad2val(adVal));
    readString = Serial1.readString();
    if (readString.startsWith("R1")){
        readString.replace("R1", "");
        
    }
}



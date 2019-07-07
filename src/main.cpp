
#include "config.h"

double adVal1 = 0.0;
double adVal2 = 0.0;
char sendStr[255] = "";
String readString = "";
double outT = 0.0;
int databits[DATA_LEN] = {1, 0, 0, 1, 1, 1, 0, 1};
int databitsIndex = 0;
double chirpMu = 2.0;
auto carrier = 0.0;

void timer2ISR(){
    digitalWrite(PIN_LED, LOW);
    outT += ModulationConfig.Ts;
    carrier = sin(2 * PI * ModulationConfig.Fc * outT);
    if (outT >= (1.0 / ModulationConfig.Rc)){
        outT = 0;
        if (++databitsIndex >= DATA_LEN)
            databitsIndex = 0;
    }
    digitalWrite(PIN_LED, HIGH);
}

void setup() {
    Serial1.begin(SERIAL_BAUD);
    Serial1.println("Hello Magnetic Communication STM32F103VET6!");

    Timer2.setPeriod(TIMER_MS * 1000);
    Timer2.attachInterrupt(TIMER_CHANNEL, timer2ISR);

    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);

    pinMode(PIN_AD1, INPUT_ANALOG);
    pinMode(PIN_AD2, INPUT_ANALOG);
    analogWrite(PB1, 35);
    dac_init(DAC, DAC_CH1 | DAC_CH2);
    dac_write_channel1(2024);
    dac_write_channel2(1024);
    DAC9767_Init();
}

void loop() {
    //delay(MAIN_LOOP_DELAY_MS);
    DAC9767_WriteData1(0xAAA);
    //adVal1 = analogRead(PIN_AD1); 
    //adVal2 = analogRead(PIN_AD2);
    
    //sprintf(sendStr, "C1:%.2f\r\nC2:%.2f\r\nC3:%.2f\r\n", adVal1, adVal2, carrier);
    //Serial1.print(sendStr);

}



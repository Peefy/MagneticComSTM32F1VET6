
#include "config.h"

double adVal1 = 0.0;
double adVal2 = 0.0;
char sendStr[60] = "";
String readString = "";
double outT = 0.0;
int databits[DATA_LEN] = {1, 0, 0, 1, 1, 1, 0, 1};
int databitsIndex = 0;
double chirpMu = 2.0;

void timer2ISR(){
    digitalWrite(PIN_LED, LOW);
    outT += ModulationConfig.Ts;
    auto carrier = sin(2 * PI * ModulationConfig.Fc * outT);
    if (outT >= (1.0 / ModulationConfig.Rc)){
        outT = 0;
        if (++databitsIndex >= DATA_LEN)
            databitsIndex = 0;
    }
    duguAnalogWrite(val2ad(carrier * (databits[databitsIndex] == 0 ? -1 : 1)), DAC_CH1);
    duguAnalogWrite(val2ad(generateChirp(outT, chirpMu * chirpMu / TIMER_MS)), DAC_CH2);
    digitalWrite(PIN_LED, HIGH);
}

void setup() {
    Serial1.begin(SERIAL_BAUD);
    Serial1.println("Hello Magnetic Communication STM32F103VET6!");
    rcc_clk_enable(RCC_GPIOA);
    digitalWrite(PA4, HIGH);
    Timer2.setPeriod(TIMER_MS * 1000);
    Timer2.attachInterrupt(TIMER_CHANNEL, timer2ISR);

    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);
    
}

void loop() {
    delay(MAIN_LOOP_DELAY_MS);
    adVal1 = analogRead(PIN_AD1); 
    adVal2 = analogRead(PIN_AD2);
    sprintf(sendStr, "C1:%.2f\r\nC2:%.2f\r\nC3:%.2f\r\n", adVal1, adVal2, ad2val(adVal1));
    readString = Serial1.readString();
    if (readString.startsWith("R:")) {
        readString.replace("R:", "");
        auto data = readString.toInt();
        for (size_t i = 0; i < DATA_LEN; i++) {
            databits[i] = BIT_GET(data, i);
        }    
    }
}



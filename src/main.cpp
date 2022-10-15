#include <Arduino.h>
#include "MainMotor.h"
#include "SecondaryMotor.h"
#define DIR 3
#define PUL 4

MainMotor mainMotor(DIR, PUL, 1600); // 尽量设置为800 或者1600 否则电机只xiang'buzhuan
SecondaryMotor secondaryMotor(8, 9, 0.5);
void setup() {
    Serial.begin(9600);
    mainMotor.setSpeed(1);
}
void loop() {
    mainMotor.runForward(4);
    for (int i = 0; i < 30000; ++i) {
        secondaryMotor.runPositive();
    }
    secondaryMotor.runPositive();
    delay(2000);
//    mainMotor.runBackward(4);
    while (true) {

    }

}
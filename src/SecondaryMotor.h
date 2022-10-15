//
// Created by Brief on 2022/9/27.
//
#include "Arduino.h"
#ifndef TESTPLATFORMIO_SECONDARYMOTOR_H
#define TESTPLATFORMIO_SECONDARYMOTOR_H


class SecondaryMotor {

public:
    SecondaryMotor(int input1, int input2, float pwm){
        this->input1 = input1;
        this->input2 = input2;
        this->pwm = pwm;
        digitalWrite(input1, LOW);
        digitalWrite(input2, LOW);
    };
    void runPositive();
    void runNegative();
    void stop();

private:
    void positive();
    void negative();
    int input1;
    int input2;
    float pwm;
};


#endif //TESTPLATFORMIO_SECONDARYMOTOR_H

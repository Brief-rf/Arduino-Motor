//
// Created by Brief on 2022/9/27.
//

#ifndef TESTPLATFORMIO_MAINMOTOR_H
#define TESTPLATFORMIO_MAINMOTOR_H
#include "Arduino.h"

class MainMotor {
public:

    MainMotor(int dirPin, int pulPin, int subdivisions){
        Serial.begin(9600);
        this->dirPin = dirPin;
        this->pulPin = pulPin;
        this->subdivisions = subdivisions;
        pinMode(dirPin, OUTPUT);
        pinMode(pulPin, OUTPUT);
    };

    void runForward(float times); // 手动设定运行
    void runBackward(float times); // 手动设定运行
    void calculatePulseTime(); // 计算前进或者后退的速度
    void sendPulse(int count);
    void setSpeed(float speed); // 设置运行速度 单位为 cm/s

    float pulseTime;
private:
    // 细分数设置为200的话，给一个脉冲是转1.8°，设置为400的话，给一个脉冲是转0.9°
    // 现在细分数为800
    int dirPin;
    int pulPin;
    float subdivisions; // 设置细分数
    // 设置脉冲时间间隔
    float speed; // 设置运行速度 单位为 cm/s
    float round_distance = 5.00; // 10mm
};


#endif //TESTPLATFORMIO_MAINMOTOR_H

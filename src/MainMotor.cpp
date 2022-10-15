//
// Created by Brief on 2022/9/27.
//

#include "MainMotor.h"
void MainMotor::setSpeed(float speed){
    this->speed = speed;
    Serial.print("speed: ");
    Serial.println(speed);
    // 设置细分数后去计算脉冲时间
    calculatePulseTime();
}
void MainMotor::calculatePulseTime() {
    // 计算前进或者后退的速度
    Serial.print("Distance Per Round: ");
    Serial.println(round_distance);
    Serial.print("Subdivisions: ");
    Serial.println(subdivisions);
    pulseTime = 1e5 * round_distance / ( this->speed * 2 * subdivisions);
    Serial.print("Pulse Time: ");
    Serial.println(pulseTime);
    this->pulseTime = pulseTime;

}
void MainMotor::runForward(float times) {
    // tiems 为圈数
    // 前进运行
    digitalWrite(dirPin, HIGH);
    sendPulse(int(times * subdivisions));
}

void MainMotor::runBackward(float times) {
    // 后退运行
    digitalWrite(dirPin, LOW);
    sendPulse(int(times * subdivisions));
}
void MainMotor::sendPulse(int count) {
    // 给定一个脉冲数，运行电机
    for(int i=0;i<count;i++)
    {
        digitalWrite(pulPin, HIGH);
        delayMicroseconds(this->pulseTime);
        digitalWrite(pulPin, LOW);
        delayMicroseconds(this->pulseTime);
    }
}
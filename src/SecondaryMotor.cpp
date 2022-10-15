//
// Created by Brief on 2022/9/27.
//

#include "SecondaryMotor.h"
void SecondaryMotor::runNegative() {
    negative();
    delayMicroseconds(int(10 * this->pwm));
    stop();
    delayMicroseconds(int(10 * (1 - this->pwm)));
}


void SecondaryMotor::runPositive() {
    // 点击逆时针旋转
    positive();
    delayMicroseconds(int(10 * this->pwm));
    stop();
    delayMicroseconds(int(10 * (1 - this->pwm)));
}

void SecondaryMotor::stop() {
    // 停止
    digitalWrite(this->input1,LOW); //给高电平
    digitalWrite(this->input2,LOW);  //给低电平
}
void SecondaryMotor::negative() {
    // 点击顺时针旋转
    digitalWrite(this->input1,LOW); //给高电平
    digitalWrite(this->input2,HIGH);  //给低电平
}
void SecondaryMotor::positive() {
    // 点击逆时针旋转
    digitalWrite(this->input1,HIGH); //给高电平
    digitalWrite(this->input2,LOW);  //给低电平
}




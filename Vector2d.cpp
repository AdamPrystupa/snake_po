//
// Created by Adam on 15.05.2023.
//

#include "Vector2d.h"
Vector2d::Vector2d(int x, int y) {
    this->ActualX=x;
    this->ActualY=y;

    this->oldX=0;
    this->oldY=0;
}

void Vector2d::setPosition(int x, int y) {
    oldX=ActualX;
    oldY=ActualY;

    ActualX=x;
    ActualY=y;
}

int Vector2d::getOldX() {
    return oldX;
}

int Vector2d::getOldY() {
    return oldY;
}

int Vector2d::getActualX() {
    return ActualX;
}

int Vector2d::getActualY() {
    return ActualY;
}
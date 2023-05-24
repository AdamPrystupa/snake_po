//
// Created by Adam on 15.05.2023.
//

#include "SnakeSegment.h"
SnakeSegment::SnakeSegment(int x, int y) {
    this->ActualX=x;
    this->ActualY=y;

    this->oldX=0;
    this->oldY=0;
}

void SnakeSegment::setPosition(int x, int y) {
    oldX=ActualX;
    oldY=ActualY;

    ActualX=x;
    ActualY=y;
}

int SnakeSegment::getOldX() {
    return oldX;
}

int SnakeSegment::getOldY() {
    return oldY;
}

int SnakeSegment::getActualX() {
    return ActualX;
}

int SnakeSegment::getActualY() {
    return ActualY;
}
//
// Created by Adam on 15.05.2023.
//

#include "SnakeBody.h"

int SnakeBody::Snake(int x, int y, int width, int height) {
    this->snakePositionX=x;
    this->snakePositionY=y;
    this->borderlineX=snakeWidth/2-1;
    this->borderlineY=snakeWidth/2-1;
}

void SnakeBody::addSegment(int x, int y) {
std::vector<Vector2d> vector;

}
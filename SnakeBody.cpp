//
// Created by Adam on 15.05.2023.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody(int x, int y, int width, int height) {
    this->snakePositionX=x;
    this->snakePositionY=y;
    this->borderlineX=snakeWidth/2-1;
    this->borderlineY=snakeWidth/2-1;
}

void SnakeBody::addSegment(int x, int y) {
Vector2d vector(snakePositionX,snakePositionY);
snakeBody.insert(snakeBody.begin(),vector);

snakePositionX=x;
snakePositionY=y;
}

void SnakeBody::moveSnake(Directions dir) {
    
}
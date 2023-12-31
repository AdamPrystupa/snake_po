//
// Created by Adam on 31.05.2023.
//

#include "Snake.h"

Snake::Snake(sf::RenderWindow &window){
    this->windowSize.x=window.getSize().x;
    this->windowSize.y=window.getSize().y;
    this->segmentShape.setFillColor(sf::Color::Green);


}

void Snake::addSnakeSegment()
{
    sf::Vector2f newSegmentPosition;
do {
    sf::Vector2f lastSegmentPosition = snake.back();
    newSegmentPosition = lastSegmentPosition + direction;
}
    while(belongsToSnake(newSegmentPosition.x,newSegmentPosition.y));

    snake.push_back(newSegmentPosition);
}


void Snake::moveSnake(const sf::Vector2f& direction)
{
    sf::Vector2f newPosition = snake[0] + direction * segmentSize;

    for (size_t i = snake.size() - 1; i > 0; --i)
    {
        snake[i] = snake[i - 1];
    }

    snake[0] = newPosition;

}

sf::Vector2f Snake::getDirection(){
    return direction;
}

float Snake::setSegmentSize(float segmentSize){
    this->segmentSize=segmentSize;
}

 const std::vector<sf::Vector2f> Snake::getSnake() {
    return snake;
}



sf::Vector2f Snake::setDirection(sf::Vector2f dir) {
    this->direction=dir;
}

sf::Vector2f Snake::setHeadPositionX(float newX) {
    this->snake[0].x=newX;
}

sf::Vector2f Snake::setHeadPositionY(float newY) {
    this->snake[0].y=newY;
}



bool Snake::isSelfCollision() {
    for (size_t segment = 1; segment < snake.size(); ++segment) {
        if (snake[segment].x == snake[0].x && snake[segment].y==snake[0].y)
            return true;
    }
    return false;
}


void Snake::setStartPosition(float xBeginning,float yBeginning,int rows, int columns) {
    sf::Vector2f startPosition(xBeginning+(columns/2*segmentSize), yBeginning+(rows/2*segmentSize));
    snake.push_back(startPosition);
    this->segmentShape.setPosition(startPosition);
    this->segmentShape.setSize(sf::Vector2f (segmentSize,segmentSize));
}


bool Snake::belongsToSnake(float x, float y) {
    for (const sf::Vector2f& segment : snake) {
        if (segment.x == x && segment.y == y)
            return true;
    }
    return false;
}


void Snake::clearSnake() {snake.clear();}

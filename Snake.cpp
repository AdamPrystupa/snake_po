//
// Created by Adam on 31.05.2023.
//

#include "Snake.h"

Snake::Snake(sf::RenderWindow &window){
    sf::Vector2f startPosition(window.getSize().x/2, window.getSize().y/2);
    this->segmentSize = 20.0f * window.getSize().x/700;
    snake.push_back(startPosition);
    this->segmentShape.setSize(sf::Vector2f (segmentSize,segmentSize));
    this->segmentShape.setPosition(startPosition);
    this->segmentShape.setFillColor(sf::Color::Green);
    addSnakeSegment();
    addSnakeSegment();
    addSnakeSegment();
    addSnakeSegment();
    addSnakeSegment();
    addSnakeSegment();


}

void Snake::addSnakeSegment()
{

    sf::Vector2f lastSegmentPosition = snake.back();
    sf::Vector2f newSegmentPosition = lastSegmentPosition + direction * segmentSize;

    snake.push_back(newSegmentPosition);
}
void Snake::moveSnake(const sf::Vector2f& direction)
{

    sf::Vector2f lastPosition = snake[0];
    snake[0] += direction * segmentSize;

    for (size_t i = 1; i < snake.size(); ++i)
    {
        sf::Vector2f currentPosition = snake[i];
        snake[i] = lastPosition;
        lastPosition = currentPosition;
    }
}

sf::Vector2f Snake::getDirection(){
    return direction;
}

float Snake::getSegmentSize(){
    return segmentSize;
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

size_t Snake::getSnakeSize() {
    return snake.size();
}
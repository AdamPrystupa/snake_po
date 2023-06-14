//
// Created by Adam on 31.05.2023.
//

#ifndef SNAKE_MW_SR11_275496_SNAKE_H
#define SNAKE_MW_SR11_275496_SNAKE_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>



class Snake {

    std::vector<sf::Vector2f> snake;
    sf::Vector2f direction;
    sf::Vector2f windowSize;
    float segmentSize;

public:
    Snake(sf::RenderWindow &window);
    sf::RectangleShape segmentShape;
    sf::Vector2f setDirection(sf::Vector2f dir);
    sf::Vector2f setHeadPositionX(float newX);
    sf::Vector2f setHeadPositionY(float newY);
    sf::Vector2f getDirection();
    float setSegmentSize(float segmentSize);
    const std::vector<sf::Vector2f> getSnake();
    void addSnakeSegment();
    void moveSnake(const sf::Vector2f& direction);
    bool isSelfCollision();
    void setStartPosition(float xBeginning,float yBeginning,int rows, int columns);
    bool belongsToSnake(float x, float y);
    void clearSnake();



};




#endif //SNAKE_MW_SR11_275496_SNAKE_H

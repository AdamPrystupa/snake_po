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
    sf::RectangleShape segmentShape;
    sf::Vector2f setDirection(sf::Vector2f dir);
    sf::Vector2f setHeadPositionX(float newX);
    sf::Vector2f setHeadPositionY(float newY);
    float getSegmentSize();
    sf::Vector2f getDirection();
    const std::vector<sf::Vector2f> getSnake();


    Snake(sf::RenderWindow &window);
    void addSnakeSegment();
    void moveSnake(const sf::Vector2f& direction);
    size_t getSnakeSize();
    bool isSelfCollision();
    float getWindowXSize();
    float getWindowYSize();
    void setStartPosition(int columns);
    bool belongsToSnake(float x, float y);



};


#endif //SNAKE_MW_SR11_275496_SNAKE_H

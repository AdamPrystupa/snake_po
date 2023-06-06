//
// Created by Adam on 31.05.2023.
//

#ifndef SNAKE_MW_SR11_275496_SNAKE_H
#define SNAKE_MW_SR11_275496_SNAKE_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>



class Snake {

    std::vector<sf::Vector2f> snake;
    sf::Vector2f direction;
    float segmentSize;
public:
    sf::RectangleShape segmentShape;

    sf::Vector2f setDirection(sf::Vector2f dir);
    float getSegmentSize();
    sf::Vector2f getDirection();
    const std::vector<sf::Vector2f> getSnake();


    Snake(sf::RenderWindow &window);
    void addSnakeSegment();
    void moveSnake(const sf::Vector2f& direction);
    bool isCollision(const sf::Vector2f& position );


};


#endif //SNAKE_MW_SR11_275496_SNAKE_H
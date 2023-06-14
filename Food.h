//
// Created by Adam on 31.05.2023.
//

#ifndef SNAKE_MW_SR11_275496_FOOD_H
#define SNAKE_MW_SR11_275496_FOOD_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <random>

#include "Snake.h"


class Food {
    sf::RectangleShape fruit;
    sf::Vector2f foodPosition;

    int columns;
    int rows;
    float segmentSize;
    int generatedFoods;

public:
    Food();
    bool isFruitCollision(sf::Vector2f snakeHeadPosition);
    int generateFood(float xBeginning,float yBeginning, Snake snake);
    void setColumns(int columns);
    void setRows(int rows);
    void setDimensions(float segmentSize);
    sf::RectangleShape getFruit();
    float getSegmentSize();
    float getFoodPositionY();
    float getFoodPositionX();
    void clearGeneratedFoods();



};


#endif //SNAKE_MW_SR11_275496_FOOD_H

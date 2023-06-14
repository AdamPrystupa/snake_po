//
// Created by Adam on 31.05.2023.
//

#include "Food.h"

Food::Food() {
    this->generatedFoods=0;
}


int Food::generateFood(float xBeginning,float yBeginning,Snake snake) {
    std::srand(std::time(0));
    do {
        foodPosition.x =  (std::rand()%columns)*segmentSize+xBeginning;
        foodPosition.y =(std::rand()%rows)*segmentSize+yBeginning;
        generatedFoods++;
                fruit.setPosition(foodPosition.x, foodPosition.y);
                fruit.setSize(sf::Vector2f(segmentSize, segmentSize));
                fruit.setOutlineThickness(2);
                fruit.setOutlineColor(sf::Color::Black);
        if (generatedFoods <= 3) {
            {
                fruit.setFillColor(sf::Color(252, 36, 3));
            }
        } else {

            fruit.setFillColor(sf::Color(240, 171, 53));

            generatedFoods = 0;
        }
    } while (snake.belongsToSnake(foodPosition.x,foodPosition.y));
    return generatedFoods;
}


bool Food::isFruitCollision(sf::Vector2f snakeHeadPosition) {
    if (snakeHeadPosition.x == foodPosition.x   && snakeHeadPosition.y == foodPosition.y) {
        return true;
    }
    return false;
}

void Food::setDimensions(float segmentSize) {
    this->segmentSize=segmentSize;
    this->fruit.setSize(sf::Vector2f (segmentSize,segmentSize));
    this->fruit.setFillColor(sf::Color::Magenta);
}

void Food::setColumns(int columns) {
    this->columns=columns;
}

void Food::setRows(int rows) {
    this->rows=rows;
}

sf::RectangleShape Food::getFruit() {
    return fruit;
}

void Food::clearGeneratedFoods() {generatedFoods=1;}
//
// Created by Adam on 01.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_BOARD_H
#define SNAKE_MW_SR11_275496_BOARD_H


#include "Food.h"
#include "Snake.h"


class Board {
    int numColumns;
    int numRows;
    float segmentSize;
    float xBeginning;
    float yBeginning;
    float xEnding;
    float yEnding;



public:
    Board(int numColumns, int numRows, sf::RenderWindow &window);
    bool isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const;
    float getXBeginning();
    float getYBeginning();
    float getXEnding();
    float getYEnding();
    float getColumns();
    float getRows();
    float getSegmentSize();







};



#endif //SNAKE_MW_SR11_275496_BOARD_H

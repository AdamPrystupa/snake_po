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
    float xBegining;
    float yBegining;
    float xEnding;
    float yEnding;

    // inne pola, takie jak jedzenie, punktacja, itp.


public:
    Board(int numColumns, int numRows);
    bool isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const;
    float getXBegining();
    float getYBegining();
    float getXEnding();
    float getYEnding();
    float getColumns();
    float getRows();
    void setSegmentSize(float segmentSize);







};



#endif //SNAKE_MW_SR11_275496_BOARD_H

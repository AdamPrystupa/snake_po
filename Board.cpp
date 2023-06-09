//
// Created by Adam on 01.06.2023.
//

#include "Board.h"
#include <iostream>

Board::Board(int numColumns, int numRows){
this->numColumns=numColumns;
this->numRows=numRows;
}



bool Board::isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const
{
    if(snakeHeadPosition.x <= xBegining || snakeHeadPosition.x >= xEnding ||
            snakeHeadPosition.y <= yBegining || snakeHeadPosition.y >= yEnding)
        return true;
    return false;
}

float Board::getXBegining() {return xBegining;}
float Board::getYBegining() {return yBegining;}
float Board::getXEnding() {return xEnding;}
float Board::getYEnding() {return yEnding;}
float Board::getColumns() {return numColumns;}
float Board::getRows() {return numRows;}

void Board::setSegmentSize(float segment) {
    segmentSize=segment;
    xBegining=(2*segmentSize);
    yBegining=(2*segmentSize);
    xEnding=numColumns * segmentSize;
    yEnding=numRows * segmentSize;

}
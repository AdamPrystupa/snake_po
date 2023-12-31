//
// Created by Adam on 01.06.2023.
//

#include "Board.h"
#include <iostream>

Board::Board(int numColumns, int numRows, sf::RenderWindow &window){
    this->yBeginning=0.05*window.getSize().y;
    this->segmentSize=0.75*window.getSize().y/numRows;
    this->xBeginning=(window.getSize().x-numColumns*segmentSize)/2;
    this->numRows=numRows;
    this->numColumns=numColumns;
    this->yEnding=yBeginning+numRows*segmentSize;
    this->xEnding=xBeginning+numColumns*segmentSize;
}



bool Board::isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const
{
    if(snakeHeadPosition.x < xBeginning || snakeHeadPosition.x > xEnding ||
       snakeHeadPosition.y < yBeginning || snakeHeadPosition.y > yEnding)
        return true;
    return false;
}

float Board::getXBeginning() {return xBeginning;}
float Board::getYBeginning() {return yBeginning;}
float Board::getXEnding() {return xEnding;}
float Board::getYEnding() {return yEnding;}
float Board::getColumns() {return numColumns;}
float Board::getRows() {return numRows;}
float Board::getSegmentSize() {return segmentSize;};


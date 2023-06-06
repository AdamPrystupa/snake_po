//
// Created by Adam on 01.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_BOARD_H
#define SNAKE_MW_SR11_275496_BOARD_H


#include "Food.h"
#include "Snake.h"


class Board {
    Snake &snake;
    int numColumns;      // liczba kolumn planszy
    int numRows;         // liczba wierszy planszy
    int segmentSize;     // wymiar pojedynczego segmentu węża
    // inne pola, takie jak jedzenie, punktacja, itp.


public:
    Board(int numColumns, int numRows, sf::RenderWindow &window, Snake &snake);
    void update(float dt);
    void handleInput(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    bool isSnakeOutOfBounds(const sf::Vector2f& snakeHeadPosition)const;





};



#endif //SNAKE_MW_SR11_275496_BOARD_H

//
// Created by Adam on 01.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_BOARD_H
#define SNAKE_MW_SR11_275496_BOARD_H


#include "Food.h"
#include "Snake.h"


class Board {
    enum GameState {STARTED,MENU,SCOREBOARD,OVER,ENDED};
    GameState gameState;
    Snake &snake;
    int numColumns;      // liczba kolumn planszy
    int numRows;         // liczba wierszy planszy
    float segmentSize;     // wymiar pojedynczego segmentu węża
    float xBegining;
    float yBegining;
    float xEnding;
    float yEnding;

    bool bordersPenetration;
    // inne pola, takie jak jedzenie, punktacja, itp.


public:
    Board(int numColumns, int numRows, sf::RenderWindow &window, Snake &snake);
    void update(float dt, sf::RenderWindow &window);
    void handleInput(sf::RenderWindow& window);
    void renderSnake(sf::RenderWindow& window);
    GameState getGameState();
    bool isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const;
    bool isCollision(const sf::Vector2f& snakeHeadPosition ) ;
    bool isFruitCollision(const sf::Vector2f& snakeHeadPosition ) const;
    bool isBodyCollision(const sf::Vector2f& snakeHeadPosition ) const;





};



#endif //SNAKE_MW_SR11_275496_BOARD_H

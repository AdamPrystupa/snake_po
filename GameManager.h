//
// Created by Adam on 07.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_GAMEMANAGER_H
#define SNAKE_MW_SR11_275496_GAMEMANAGER_H

#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "iostream"

#include <chrono>
#include <thread>


class GameManager {
    Snake &snake;
    Board &board;
    Food &fruit;
    enum GameState {STARTED, MENU, SCOREBOARD, OVER, ENDED};
    GameState gameState;
    bool bordersPenetration;
    bool isFruitGenerated;
    bool areDimensionsSeted;
    bool isStartPosition;
    int generatedFruitCount;
    float moveInterval;

public:
    GameManager(Snake &snake, Board &board, Food &fruit);
    void handleInput(sf::RenderWindow& window);
    void update(float dt,sf::RenderWindow &window);
    void renderSnake(sf::RenderWindow& window);
    bool isCollision();
    void whenOutOfBorders();
    void whenFruitCollision();
    void whenSelfCollison();
    void setDimensions();
};

#endif //SNAKE_MW_SR11_275496_GAMEMANAGER_H

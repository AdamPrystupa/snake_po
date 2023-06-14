//
// Created by Adam on 07.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_GAMEMANAGER_H
#define SNAKE_MW_SR11_275496_GAMEMANAGER_H

#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "iostream"
#include "View.h"

#include <chrono>
#include <thread>


class GameManager {
    Snake &snake;
    Board &board;
    Food &fruit;
    View &view;
    enum GameState {STARTED, MENU, OPTIONS, SCOREBOARD, OVER, ENDED};
    GameState gameState;
    bool easy;
    bool normal;
    bool hard;
    bool bordersPenetration;
    bool checkboxClicked;
    bool isFruitGenerated;
    bool areDimensionsSeted;
    bool isStartPosition;
    int generatedFruitCount;
    float moveInterval;
    float dt;
    bool keyPressed;
    bool areStringsInitialized;

    sf::Text gameName;
    sf::Text menuStrings[3];
    sf::Font font;

public:
    GameManager(Snake &snake, Board &board, Food &fruit, View &view);
    void handleInput(sf::RenderWindow& window);
    void update(sf::RenderWindow &window);
    void snakeDisplay(sf::RenderWindow& window);
    bool isCollision();
    void whenOutOfBorders();
    void whenFruitCollision();
    void whenSelfCollison();
    void setDimensions();
    void whenStarted(sf::Event &event);
    void caseStarted(sf::RenderWindow& window);
    void caseMenu( sf::RenderWindow &window);
    void caseOver(sf::RenderWindow& window);
    void caseOptions(sf::RenderWindow& window);
    void optionsActions(sf::RenderWindow &window, sf::Event &event);
    void overActions(sf::RenderWindow &window, sf::Event &event);
    void menuActions(sf::RenderWindow &window, sf::Event &event);
    void setDt(float dt);

};

#endif //SNAKE_MW_SR11_275496_GAMEMANAGER_H

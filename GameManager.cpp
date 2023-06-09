//
// Created by Adam on 07.06.2023.
//

#include "GameManager.h"

GameManager::GameManager(Snake &snake, Board &board, Food &fruit): snake(snake),board(board),fruit(fruit) {
    this->gameState = STARTED;
    this->bordersPenetration = true;
    this->generatedFruitCount = 0;
    this->isFruitGenerated = false;
    this->moveInterval = 0.1f;
}

void GameManager::setDimensions() {
    board.setSegmentSize(snake.getSegmentSize());
    fruit.setColumns(board.getColumns());
    fruit.setRows(board.getRows());
    fruit.setDimensions(snake.getSegmentSize());
    areDimensionsSeted=true;
}


void GameManager::update(float dt,sf::RenderWindow &window) {
    {
        switch (gameState) {
//            case Board::MENU:
//                renderMenu();
//                break;
//
//            case Board::SCOREBOARD:
//                renderScoreboard();
//                break;
//
            case GameManager::STARTED: {
                if (!isStartPosition) {
                    snake.setStartPosition(board.getColumns());
                    isStartPosition = true;
                }
                if (!areDimensionsSeted)
                    setDimensions();


                static float elapsedTime = 0.0f;
                elapsedTime += dt;
                if (elapsedTime >= moveInterval) {

                    if (gameState == STARTED) {
                        handleInput(window);
                        snake.moveSnake(snake.getDirection());
                        if (!isFruitGenerated) {
                            generatedFruitCount = fruit.generateFood(board.getXBegining(), board.getYBegining(), snake);
                            isFruitGenerated = true;
                        }
                        isCollision();
                        elapsedTime = 0.0f;
                    }
                }
                break;
            }
//
            case GameManager::OVER:



                break;
//
//            case Board::ENDED:
//                renderWindow.close();
//                return;
//                break;
//        }
//    }

        }
    }
}
void GameManager::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if(gameState!=STARTED)
                gameState=STARTED;
            sf::Vector2f currentDirection = snake.getDirection();
            if (currentDirection.y == 0)
            {
                if (event.key.code == sf::Keyboard::Up && snake.getDirection().y == 0)
                    snake.setDirection(sf::Vector2f(0.0f, -1.0f));
                 if (event.key.code == sf::Keyboard::Down && snake.getDirection().y == 0)
                    snake.setDirection(sf::Vector2f(0.0f, 1.0f));
            }
            if (currentDirection.x == 0)
            {
                if (event.key.code == sf::Keyboard::Left && snake.getDirection().x == 0)
                    snake.setDirection(sf::Vector2f(-1.0f, 0.0f));
                if (event.key.code == sf::Keyboard::Right && snake.getDirection().x == 0)
                    snake.setDirection(sf::Vector2f(1.0f, 0.0f));
            }
        }
    }
}


void GameManager::renderSnake(sf::RenderWindow& window)
{

    window.clear();

    for (const sf::Vector2f& segment : snake.getSnake()) {
        snake.segmentShape.setPosition(segment);
        window.draw(snake.segmentShape);
    }

    window.draw(fruit.getFruit());
    window.display();
}


bool GameManager::isCollision() {

    if (gameState == STARTED) {
        if (fruit.isFruitCollision(snake.getSnake()[0])) {
            whenFruitCollision();
            return true;
        }
        if (board.isSnakeOutOfBorders(snake.getSnake()[0])) {
           whenOutOfBorders();
            return true;
        }

        if (snake.isSelfCollision()) {
            whenSelfCollison();
            return true;
        }
        return false;
    }
}

void GameManager::whenOutOfBorders() {
    if (bordersPenetration == true) {
        if (snake.getSnake()[0].y > board.getYEnding())
            snake.setHeadPositionY(board.getYBegining());
        if (snake.getSnake()[0].y < board.getYBegining())
            snake.setHeadPositionY(board.getYEnding());
        if (snake.getSnake()[0].x > board.getXEnding())
            snake.setHeadPositionX(board.getXBegining());
        if (snake.getSnake()[0].x < board.getXBegining())
            snake.setHeadPositionX(board.getXEnding());
    }
    else
        gameState=OVER;
}

void GameManager::whenFruitCollision() {
    isFruitGenerated= false;
    if(generatedFruitCount==0) {
        snake.addSnakeSegment();
        snake.addSnakeSegment();
        snake.addSnakeSegment();
        snake.addSnakeSegment();
    }
    else
        snake.addSnakeSegment();
}

void GameManager::whenSelfCollison() {

    gameState = OVER;
}

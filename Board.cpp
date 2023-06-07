//
// Created by Adam on 01.06.2023.
//

#include "Board.h"
#include <iostream>

Board::Board(int numColumns, int numRows, sf::RenderWindow &window, Snake &snake): snake(snake){
    this->bordersPenetration= false;
    this->numColumns=numColumns;
    this->numRows=numRows;
    this->segmentSize = snake.getSegmentSize();
    this->xBegining=(window.getSize().x-numColumns*segmentSize)/2;
    this->yBegining=(window.getSize().y-numRows*segmentSize)/2;
    this->xEnding=numColumns * segmentSize + xBegining;
    this->yEnding=numRows * segmentSize + yBegining;
    this->gameState=MENU;
    this->boardWidth=numColumns*segmentSize;
    this->boardHeight=numRows*segmentSize;
    this->isFruitGenerated=false;

}

void Board::update(float dt, sf::RenderWindow &window)
{
//    {
//        switch(gameState)
//        {
//            case Board::MENU:
//                renderMenu();
//                break;
//
//            case Board::SCOREBOARD:
//                renderScoreboard();
//                break;
//
//            case Board::STARTED:
//                drawGame();
//                break;
//
//            case Board::OVER:
//                gameOver();
//                break;
//
//            case Board::ENDED:
//                renderWindow.close();
//                return;
//                break;
//        }
//    }

    float moveInterval = 0.2f;
    static float elapsedTime = 0.0f;
    elapsedTime += dt;
    if (elapsedTime >= moveInterval)
    {

        if(gameState==STARTED)
            snake.moveSnake(snake.getDirection());
        if(!isFruitGenerated)
            generateFruit();
        window.draw(smallFood);
        isCollision();
        elapsedTime = 0.0f;
    }
}
void Board::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if(gameState!=STARTED)
                gameState=STARTED;
            if (event.key.code == sf::Keyboard::Up && snake.getDirection().y==0)
                snake.setDirection(sf::Vector2f(0.0f, -1.0f));
            else if (event.key.code == sf::Keyboard::Down && snake.getDirection().y==0)
                snake.setDirection(sf::Vector2f(0.0f, 1.0f));
            else if (event.key.code == sf::Keyboard::Left && snake.getDirection().x==0)
                snake.setDirection(sf::Vector2f(-1.0f, 0.0f));
            else if (event.key.code == sf::Keyboard::Right&& snake.getDirection().x==0)
                snake.setDirection(sf::Vector2f(1.0f, 0.0f));
        }
    }
}
void Board::renderSnake(sf::RenderWindow& window)
{
    window.clear();

    for (const sf::Vector2f& segment : snake.getSnake()) {
        snake.segmentShape.setPosition(segment);
        window.draw(snake.segmentShape);
    }

    window.display();
}
sf::Vector2f Board::generateFruit()
{
    std::cout<<"TWORZENIE"<<std::endl;
    std::srand(std::time(0));
    sf::Vector2f foodPosition;
    foodPosition.x=(std::rand()%int(boardWidth)+segmentSize);
    foodPosition.y=(std::rand()%int(boardHeight)+segmentSize);
    smallFood.setPosition(sf::Vector2f(foodPosition.x,foodPosition.y));
    isFruitGenerated=true;
}

bool Board::isSnakeOutOfBorders(const sf::Vector2f& snakeHeadPosition)const
{
    if(snakeHeadPosition.x <= xBegining || snakeHeadPosition.x >= xEnding ||
            snakeHeadPosition.y <= yBegining || snakeHeadPosition.y >= yEnding)
    {std::cout<<"BORDER"<<std::endl;
        return true;}
}

bool Board::isCollision()  {
    if(gameState==STARTED)
    if(isSnakeOutOfBorders(snake.getSnake()[0]))
    {
        if(bordersPenetration== false)
           // gameState=OVER;

            if (snake.getSnake()[0].x > xEnding)
                snake.setHeadPositionX(xBegining);
            else if (snake.getSnake()[0].x < xBegining)
                snake.setHeadPositionX(xEnding); // Przejście na koniec planszy
            if (snake.getSnake()[0].y > yEnding)
                snake.setHeadPositionY(yBegining); // Przejście na początek planszy
            else if (snake.getSnake()[0].y < yBegining)
                snake.setHeadPositionY(yEnding); // Przejście na koniec planszy


    }


//    if(isFruitCollision(snake.getSnake()[0]))
    {

    }

    if(isBodyCollision(snake.getSnake()[0] )&& gameState==STARTED)
    {

        std::cout << "COLLISION" << std::endl;
        gameState=OVER;
    }

}

bool Board::isBodyCollision(const sf::Vector2f &snakeHeadPosition) const {
    for (size_t segment = 1; segment < snake.getSnakeSize(); ++segment) {
        if (snake.getSnake()[segment].x == snakeHeadPosition.x && snake.getSnake()[segment].y==snakeHeadPosition.y)
            return true;

    }
        return false;
}
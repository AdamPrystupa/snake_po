//
// Created by Adam on 01.06.2023.
//

#include "Board.h"
#include <iostream>

Board::Board(int numColumns, int numRows, sf::RenderWindow &window, Snake &snake): snake(snake){

    this->numColumns=numColumns;
    this->numRows=numRows;
    this->segmentSize = snake.getSegmentSize();

}

void Board::update(float dt)
{
    float moveInterval = 0.1f;
    static float elapsedTime = 0.0f;

    elapsedTime += dt;
    if (elapsedTime >= moveInterval)
    {
        snake.moveSnake(snake.getDirection());



//        sf::Vector2f headPosition = snake.getHeadPosition();
//        if (isSnakeOutOfBounds(headPosition))
//        {
//            // Wąż wychodzi poza mapę, wykonaj odpowiednie działania
//            // np. zakończ grę, zresetuj pozycję węża itp.
//        }
//
//        if (snake.isSelfColliding())
//        {
//            // Wąż koliduje sam ze sobą, wykonaj odpowiednie działania
//            // np. zakończ grę, zresetuj pozycję węża itp.
//        }
//
//        if (snake.isEatingFood(food))
//        {
//            // Wąż zjada jedzenie, wykonaj odpowiednie działania
//            // np. zwiększ punktację, wygeneruj nowe jedzenie itp.
//        }

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
            if (event.key.code == sf::Keyboard::Up)
                snake.setDirection(sf::Vector2f(0.0f, -1.0f));
            else if (event.key.code == sf::Keyboard::Down)
                snake.setDirection(sf::Vector2f(0.0f, 1.0f));
            else if (event.key.code == sf::Keyboard::Left)
                snake.setDirection(sf::Vector2f(-1.0f, 0.0f));
            else if (event.key.code == sf::Keyboard::Right)
                snake.setDirection(sf::Vector2f(1.0f, 0.0f));
        }
    }
}
void Board::render(sf::RenderWindow& window)
{
    window.clear();

    for (const sf::Vector2f& segment : snake.getSnake()) {
        snake.segmentShape.setPosition(segment);
        snake.segmentShape.setFillColor(sf::Color::Green);
        window.draw(snake.segmentShape);
    }

    window.display();
}

bool Board::isSnakeOutOfBounds(const sf::Vector2f& snakeHeadPosition)const
{
    return (snakeHeadPosition.x < 0 || snakeHeadPosition.x >= numColumns * segmentSize ||
            snakeHeadPosition.y < 0 || snakeHeadPosition.y >= numRows * segmentSize);
}
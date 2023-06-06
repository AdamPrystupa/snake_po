#include <SFML/Graphics.hpp>

#include <iostream>

#include "Snake.h"
#include "Food.h"
#include "Board.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 670), "Snake Game");
    Snake snake(window);
    Board board(24,18,window, snake);


        sf::Clock clock;
        while (window.isOpen()) {
            float dt = clock.restart().asSeconds();

            board.handleInput(window);
            board.update(dt,window);
            board.renderSnake(window);

        }

        return 0;
    }









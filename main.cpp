#include <SFML/Graphics.hpp>

#include <iostream>

#include "Snake.h"
#include "Food.h"
#include "Board.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Snake Game");
    Snake snake(window);
    Board board(12,10,window, snake);


        sf::Clock clock;
        while (window.isOpen()) {
            float dt = clock.restart().asSeconds();

            board.handleInput(window);
            board.update(dt);
            board.render(window);

        }

        return 0;
    }









#include <SFML/Graphics.hpp>

#include <iostream>

#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "GameManager.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1120, 880), "Snake Game");
    Snake snake(window);
    Board board(24,18);
    Food fruit;
    GameManager game(snake,board,fruit);


        sf::Clock clock;
        while (window.isOpen()) {
            float dt = clock.restart().asSeconds();


            game.update(dt,window);
            game.renderSnake(window);

        }

        return 0;
    }









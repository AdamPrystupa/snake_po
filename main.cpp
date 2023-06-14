#include <SFML/Graphics.hpp>

#include <iostream>

#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "GameManager.h"
#include "View.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Snake Game");
    Board board(20,12,window);
    Snake snake(window);
    Food fruit;
    View view(snake,board);
   GameManager game(snake,board,fruit,view);


        sf::Clock clock;
        while (window.isOpen()) {
            game.setDt(clock.restart().asSeconds());
            game.update(window);


        }

        return 0;
    }








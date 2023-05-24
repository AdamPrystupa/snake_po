#include "Game.h"
#include "SnakeBody.h"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
/*
    Game game;

    sf::RenderWindow window(sf::VideoMode(800,600),"SNAKE");
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)
                window.close();

        }
        window.clear();

        window.display();
    }*/
SnakeBody Snake(5,10,800,400);


    return 0;
    }

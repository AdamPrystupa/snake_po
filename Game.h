//
// Created by Adam on 15.05.2023.
//

#ifndef CPP_SNAKE_GAME_H
#define CPP_SNAKE_GAME_H
#include <SFML/Graphics.hpp>


class Game {
    enum GameState {STARTED,MENU,SETTINGS,OVER,ENDED};
    GameState gameState;
    sf::RenderWindow window;
public:
    void play();

};


#endif //CPP_SNAKE_GAME_H

//
// Created by Adam on 15.05.2023.
//

#ifndef CPP_SNAKE_SNAKEBODY_H
#define CPP_SNAKE_SNAKEBODY_H

#include <SFML/Graphics.hpp>
#include "Vector2d.h"
#include <vector>


class SnakeBody {


private:
    int snakePositionX, snakePositionY; //Max 20 in X (800/40) and max 15 in Y (600/40)
    int borderlineX, borderlineY;
    int snakeWidth;
    std::vector <Vector2d> snakeBody;


public:

    Snake(int x, int y, int width, int height);

    int getX();
    int getY();

    void addSegment(int x, int y);
};


#endif //CPP_SNAKE_SNAKEBODY_H

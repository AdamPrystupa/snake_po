//
// Created by Adam on 15.05.2023.
//

#ifndef CPP_SNAKE_VECTOR2D_H
#define CPP_SNAKE_VECTOR2D_H


class Vector2d {
    int ActualX;
    int ActualY;
    int oldX;
    int oldY;
public:
    Vector2d(int x, int y);
    void setPosition(int x, int y);

    int getActualX();
    int getActualY();
    int getOldX();
    int getOldY();


};


#endif //CPP_SNAKE_VECTOR2D_H

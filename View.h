//
// Created by Adam on 01.06.2023.
//

#ifndef SNAKE_MW_SR11_275496_VIEW_H
#define SNAKE_MW_SR11_275496_VIEW_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Snake.h"
#include "Board.h"


class View {
    sf::RectangleShape boardShape;
    Snake &snake;
    Board &board;
    sf::Text title;
    sf::Text menu[3];
    sf::Text options[7];
    sf::Text over[5];
    sf::Text points;
    sf::Text clockText;
    sf::RectangleShape checkbox;
    sf::Font font;
    sf::Clock clock;
    sf::Time gameTime;
    std::string timeString;

public:
    View(Snake &snake, Board &board);
    sf::RectangleShape getBoardShape();
    void boardShapeInitiation();
    void initializeFonts();
    sf::Text getTitle();
    sf::Text getMenu(int i);
    sf::Text getOptions(int i);
    sf::Text getOvers(int i);
    sf::RectangleShape getCheckbox();
    void setTextColor(int i, sf::Color color);
    sf::Font getFont();
    void setMenu(sf::RenderWindow &window);
    void setOptions(sf::RenderWindow &window);
    void setOver(sf::RenderWindow &window);
    void setClock();
    void setOptionsBacklights( sf::Vector2f mouse,bool easy, bool normal, bool hard, bool borders);
    void setOversBacklights(sf::Vector2f mouse);
    void menuDisplay(sf::RenderWindow &window, sf::Vector2f mouse);
    void optionsDisplay(sf::RenderWindow &window);
    void oversDisplay(sf::RenderWindow &window);
    void updateGameTime();
    sf::Time getGameTime() const;
    void drawClock(sf::RenderWindow &window);



};


#endif //SNAKE_MW_SR11_275496_VIEW_H

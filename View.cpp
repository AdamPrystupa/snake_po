//
// Created by Adam on 01.06.2023.
//

#include "View.h"


View::View(Snake &snake, Board &board ): snake(snake), board(board) {
    boardShapeInitiation();
}

sf::RectangleShape View::getBoardShape(){
    return boardShape;
}

void View::boardShapeInitiation() {
    boardShape.setSize(sf::Vector2f(board.getXEnding()-board.getXBeginning()+board.getSegmentSize(),board.getYEnding()-board.getYBeginning()+board.getSegmentSize()));
    boardShape.setPosition(sf::Vector2f(board.getXBeginning(),board.getYBeginning()));
    boardShape.setFillColor(sf::Color(152, 168, 69));
    boardShape.setOutlineColor(sf::Color(48, 40, 40));
    boardShape.setOutlineThickness(5.0f);
}

void View::initializeFonts()
{
    font.loadFromFile("..\\fonts\\font.otf");
}

sf::Text View::getMenu(int i) {return menu[i];}
sf::Text View::getOptions(int i) {return options[i];}
sf::Text View::getOvers(int i) {return over[i];}
sf::Text View::getScores(int i) {return scores[i];}
sf::RectangleShape View::getCheckbox(){return checkbox;}


void View::setMenu(sf::RenderWindow &window) {
    title.setFont(font);
    title.setString("Snake");
    title.setCharacterSize(80);
    title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2,250);

    menu[0].setFont(font);
    menu[0].setString("Start Game");
    menu[0].setCharacterSize(40);
    menu[0].setPosition(window.getSize().x/2-menu[0].getGlobalBounds().width/2,350);

    menu[1].setFont(font);
    menu[1].setString("Options");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(window.getSize().x/2-menu[1].getGlobalBounds().width/2,400);

    menu[2].setFont(font);
    menu[2].setString("Best sores");
    menu[2].setCharacterSize(40);
    menu[2].setPosition(window.getSize().x/2-menu[2].getGlobalBounds().width/2,450);

    menu[3].setFont(font);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(40);
    menu[3].setPosition(window.getSize().x/2-menu[3].getGlobalBounds().width/2,500);
}


void View::menuDisplay(sf::RenderWindow &window, sf::Vector2f mouse)
{
    window.clear();
    for (int i = 0; i < 4; i++)
        window.draw(menu[i]);

    for (int i = 0; i < 4; i++)
    {
        if (menu[i].getGlobalBounds().contains(mouse))
            menu[i].setFillColor(sf::Color(179, 164, 164));
        else
            menu[i].setFillColor(sf::Color::White);
    }

    window.draw(title);
    window.display();

    setMenu(window); // Dodaj to wywołanie tutaj
}


void View::setOptions(sf::RenderWindow &window)
{
    options[0].setString("OPTIONS");
    options[1].setString("Game mode:");
    options[2].setString("Border collision");
    options[3].setString("Back to manu");
    options[4].setString("Easy");
    options[5].setString("Normal");
    options[6].setString("HARD!");

    options[0].setFont(font);
    options[0].setCharacterSize(80);
    options[0].setPosition(window.getSize().x/2-options[0].getGlobalBounds().width/2, 50);

    //Draw
    for(int i = 1; i < 4; i++)
    {
        options[i].setFont(font);
        options[i].setCharacterSize(40);
        options[i].setPosition(window.getSize().x/2-options[i].getGlobalBounds().width/2, 100+100*i);
    }

    float totalWidth = options[4].getGlobalBounds().width + options[5].getGlobalBounds().width + options[6].getGlobalBounds().width;
    float spacing = (window.getSize().x - totalWidth) / 4;

    options[4].setFont(font);
    options[4].setCharacterSize(30);
    options[4].setPosition(spacing +180, 240);

    options[5].setFont(font);
    options[5].setCharacterSize(30);
    options[5].setPosition(spacing+ options[4].getGlobalBounds().width+ 230, 240);

    options[6].setFont(font);
    options[6].setCharacterSize(30);
    options[6].setPosition(spacing  + options[4].getGlobalBounds().width + options[5].getGlobalBounds().width+280, 240);

    checkbox.setSize(sf::Vector2f(20,20));
    checkbox.setOutlineColor(sf::Color::White);
    checkbox.setFillColor(sf::Color::Black);
    checkbox.setOutlineThickness(5);
    checkbox.setPosition(window.getSize().x/2+options[2].getGlobalBounds().width/1.8,315);
}

void View::setOptionsBacklights(sf::Vector2f mouse, bool easy, bool normal, bool hard, bool borders) {

    if(options[4].getGlobalBounds().contains(mouse) && !easy) //Change 'Back' string color to green on mouse hover
        options[4].setFillColor(sf::Color(179, 164, 164));
    else
        options[4].setFillColor(sf::Color::White);


    if(options[5].getGlobalBounds().contains(mouse) && !normal)
        options[5].setFillColor(sf::Color(179, 164, 164));
    else
        options[5].setFillColor(sf::Color::White);


    if(options[6].getGlobalBounds().contains(mouse) && !hard)
        options[6].setFillColor(sf::Color(179, 164, 164));
    else
        options[6].setFillColor(sf::Color::White);

    if(options[3].getGlobalBounds().contains(mouse))
        options[3].setFillColor(sf::Color(179, 164, 164));
    else
        options[3].setFillColor(sf::Color::White);


    if(easy)
        options[4].setFillColor(sf::Color(115, 114, 114));
    if(normal)
        options[5].setFillColor(sf::Color(115, 114, 114));
    if(hard)
        options[6].setFillColor(sf::Color(115, 114, 114));


    if(!borders)
        checkbox.setFillColor(sf::Color(179, 164, 164));
    else
        checkbox.setFillColor(sf::Color::Black);


}

void View::optionsDisplay(sf::RenderWindow &window) {
    window.clear();

    for(int i = 1; i < 7; i++)
        window.draw(options[i]);

    window.draw(checkbox);

    window.display();
}

void View::setOver(sf::RenderWindow &window) {

    for(int i = 0; i < 5; i++) {
        over[i].setFont(font);
    }

    over[0].setString("Game Over!");
    over[0].setCharacterSize(80);
    over[0].setPosition(window.getSize().x/2-over[0].getGlobalBounds().width/2,150);
    over[0].setFillColor(sf::Color::Red);
    over[0].setOutlineColor(sf::Color::Black);
    over[0].setOutlineThickness(2);

    over[1].setString("Score :");
    over[1].setCharacterSize(60);
    over[1].setPosition(window.getSize().x/2-0.5*over[1].getGlobalBounds().width,310);
    over[1].setOutlineColor(sf::Color::Black);
    over[1].setOutlineThickness(2);


    over[2].setString("Try again");
    over[2].setCharacterSize(40);
    over[2].setPosition(window.getSize().x/2-over[1].getGlobalBounds().width,410);
    over[2].setOutlineColor(sf::Color::Black);
    over[2].setOutlineThickness(2);

    over[3].setString("Back to menu");
    over[3].setCharacterSize(40);
    over[3].setPosition(window.getSize().x/2-over[1].getGlobalBounds().width,460);
    over[3].setOutlineColor(sf::Color::Black);
    over[3].setOutlineThickness(2);

}

void View::oversDisplay(sf::RenderWindow &window) {
    over[1].setString(points.getString());


    for(int i = 0; i < 4; i++) {
        window.draw(over[i]);
    }
    window.display();

}

void View::setOversBacklights(sf::Vector2f mouse) {
    if (over[2].getGlobalBounds().contains(mouse)) {
        over[2].setFillColor(sf::Color(179, 164, 164));
    }
    else
        over[2].setFillColor(sf::Color::White);

    if (over[3].getGlobalBounds().contains(mouse))
        over[3].setFillColor(sf::Color(179, 164, 164));
    else
        over[3].setFillColor(sf::Color::White);
}

void View::setScore(){
    points.setFont(font);
    points.setString("SCORE: ");
    points.setFillColor(sf::Color::White);
    points.setPosition(20,20);
    points.setCharacterSize(35);


}
void View::scoreDisplay(sf::RenderWindow &window){
    window.draw(points);
}

void View::updateScore(int pkt)
{
    std::string updatedScore="Score: "+std::to_string(pkt);
    this->points.setString(updatedScore);
}

void View::setBests(sf::RenderWindow &window, std::vector<int> bests) {
    scores[0].setString("BEST SCORES");
    scores[1].setString("#1 "+std::to_string(bests[0]));
    scores[2].setString("#2 "+std::to_string(bests[1]));
    scores[3].setString("#3 "+std::to_string(bests[2]));
    scores[4].setString("#4 "+std::to_string(bests[3]));
    scores[5].setString("#5 "+std::to_string(bests[4]));
    scores[6].setString("Back to menu");

    scores[0].setFont(font);
    scores[0].setCharacterSize(80);
    scores[0].setPosition(window.getSize().x/2-scores[0].getGlobalBounds().width/2, 50);

    for(int i = 1; i < 7; i++)
    {
        scores[i].setFont(font);
        scores[i].setCharacterSize(40);
        scores[i].setPosition(window.getSize().x/2-scores[i].getGlobalBounds().width/2, 100+100*i);
    }
    scores[6].setPosition(window.getSize().x/2-scores[6].getGlobalBounds().width/2, 700);

}


void View::bestsDisplay(sf::RenderWindow &window) {
    window.clear();

    for(int i = 0; i < 7; i++)
        window.draw(scores[i]);
    window.display();


}

void View::setBestsBacklights(sf::Vector2f mouse) {

    if(scores[6].getGlobalBounds().contains(mouse))
        scores[6].setFillColor(sf::Color(179, 164, 164));
    else
        scores[6].setFillColor(sf::Color::White);

}


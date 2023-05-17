//
// Created by Adam on 15.05.2023.
//

#include "Game.h"


void Game::play();
{
    sf::Event event;

    while(gameState == Game::MENU)
    {
        sf::Vector2f mouse(sf::Mouse::getPosition());

        while(renderWindow.pollEvent(event))
        {
            //Exit after clicking X on window
            if(event.type == Event::Closed)
                gameState = ENDED;

            //Go to game, options or exit when user selects option in menu
            if(event.type == Event::MouseButtonReleased)
            {
                if(menuStrings[0].getGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
                    gameState = STARTED;

                if(menuStrings[1].getGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
                    gameState = OPTIONS;

                if(menuStrings[2].getGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
                    gameState = ENDED;

            }
        }

        renderWindow.clear();

        renderWindow.draw(gameName);

        for(int i = 0; i < 3; i++)
            renderWindow.draw(menuStrings[i]);

        for(int i = 0; i < 3; i++)
            if(menuStrings[i].getGlobalBounds().contains(mouse))
                menuStrings[i].setFillColor(Color::Green);
            else
                menuStrings[i].setFillColor(Color::White);


        wind.display();
    }

    updateGame();
}
//
// Created by Adam on 07.06.2023.
//

#include "GameManager.h"

GameManager::GameManager(Snake &snake, Board &board, Food &fruit, View& view): snake(snake),board(board),fruit(fruit), view(view){
    this->gameState = MENU;
    this->bordersPenetration = false;
    this->generatedFruitCount = 0;
    this->isFruitGenerated = false;
    this->moveInterval = 0.1;
    this->normal=true;
    this->easy= false;
    this->hard= false;
    this->keyPressed=false;
    this->areStringsInitialized= false;
    this->areDimensionsSeted=false;

}

void GameManager::setDimensions() {
    fruit.setColumns(board.getColumns());
    fruit.setRows(board.getRows());
    snake.setSegmentSize(board.getSegmentSize());
    fruit.setDimensions(board.getSegmentSize());
    areDimensionsSeted=true;
}

void GameManager::setDt(float dt) {
    this->dt=dt;
}


void GameManager::update(sf::RenderWindow &window) {
    {
        if(!areStringsInitialized)
        {
            view.setMenu(window);
            view.initializeFonts();
            view.setOptions(window);
            view.setOver(window);
            view.setBests(window);
            view.setScore();
            areStringsInitialized=true;
        }
        statesSwitch(window);
        }

        }



void GameManager::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            gameState = ENDED;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if(gameState==STARTED)
                whenStarted(event);
            }
        }
    }



void GameManager::whenStarted(sf::Event &event) {
if(keyPressed==false) {
    keyPressed = true;
    sf::Vector2f currentDirection = snake.getDirection();
    if (currentDirection.y == 0) {
        if (event.key.code == sf::Keyboard::Up && snake.getDirection().y == 0)
            snake.setDirection(sf::Vector2f(0.0f, -1.0f));
        if (event.key.code == sf::Keyboard::Down && snake.getDirection().y == 0)
            snake.setDirection(sf::Vector2f(0.0f, 1.0f));
    }
    if (currentDirection.x == 0) {
        if (event.key.code == sf::Keyboard::Left && snake.getDirection().x == 0)
            snake.setDirection(sf::Vector2f(-1.0f, 0.0f));
        if (event.key.code == sf::Keyboard::Right && snake.getDirection().x == 0)
            snake.setDirection(sf::Vector2f(1.0f, 0.0f));

    }
}
}

void GameManager::snakeDisplay(sf::RenderWindow& window)
{
    window.clear();
    sf::RectangleShape boardShape = view.getBoardShape();
    window.draw(view.getBoardShape());

    bool isFirstSegment = true;

    for (size_t i = 0; i < snake.getSnake().size(); i++) {
        sf::Vector2f segment = snake.getSnake()[i];
        snake.segmentShape.setPosition(segment);
        if (isFirstSegment) {
            snake.segmentShape.setFillColor(sf::Color(4, 74, 21));
            snake.segmentShape.setOutlineColor(sf::Color::Black);
            snake.segmentShape.setOutlineThickness(1);
            isFirstSegment = false;
        } else {

            snake.segmentShape.setFillColor(sf::Color(5, 110, 30));
        }

        window.draw(snake.segmentShape);
    }
    view.scoreDisplay(window);
    window.draw(fruit.getFruit());
    window.display();
}



bool GameManager::isCollision() {

    if (gameState == STARTED) {
        if (fruit.isFruitCollision(snake.getSnake()[0])) {
            whenFruitCollision();
            return true;
        }
        if (board.isSnakeOutOfBorders(snake.getSnake()[0])) {
           whenOutOfBorders();
            return true;
        }

        if (snake.isSelfCollision()) {
            whenSelfCollision();
            return true;
        }
        return false;
    }
}

void GameManager::whenOutOfBorders() {
    if (bordersPenetration == true) {
        if (snake.getSnake()[0].y > board.getYEnding())snake.setHeadPositionY(board.getYBeginning());
        if (snake.getSnake()[0].y < board.getYBeginning())snake.setHeadPositionY(board.getYEnding());
        if (snake.getSnake()[0].x > board.getXEnding())snake.setHeadPositionX(board.getXBeginning());
        if (snake.getSnake()[0].x < board.getXBeginning())snake.setHeadPositionX(board.getXEnding());
    }
    else
    {
        snake.setDirection(sf::Vector2f(0.0f,0.0f));
        gameState=OVER;
}
}
void GameManager::whenFruitCollision() {
    isFruitGenerated= false;
    if(generatedFruitCount==0) {
        snake.addSnakeSegment(); snake.addSnakeSegment(); snake.addSnakeSegment(); snake.addSnakeSegment();
        score+=4;
        view.updateScore(score);
    }
    else { snake.addSnakeSegment();
    score++;
        view.updateScore(score);}

}

void GameManager::whenSelfCollision() {
    snake.setDirection(sf::Vector2f(0.0f,0.0f));
    gameState = OVER;

}

void GameManager::caseStarted(sf::RenderWindow &window)
{
                setParameters();
                static float elapsedTime = 0.0f;
                elapsedTime += dt;
                if (elapsedTime >= moveInterval) {

                    if (gameState == STARTED) {
                        keyPressed= false;
                        handleInput(window);
                        snake.moveSnake(snake.getDirection());
                        if (!isFruitGenerated) {
                            generatedFruitCount = fruit.generateFood(board.getXBeginning(), board.getYBeginning(), snake);
                            isFruitGenerated = true;
                        }
                        isCollision();
                        elapsedTime = 0.0f;
                    }
                }
}

void GameManager::caseMenu(sf::RenderWindow& window)
{
    sf::Event event;

    while (gameState == GameManager::MENU)
    {
        menuActions(window, event);
    }
    update(window);
}

void GameManager::menuActions(sf::RenderWindow &window, sf::Event &event) {

    sf::Vector2f mouse(sf::Mouse::getPosition(window));

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            gameState = ENDED;
        if(event.type == sf::Event::MouseButtonReleased)
        {
            if(view.getMenu(0).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                gameState = STARTED;

            if(view.getMenu(1).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                gameState = OPTIONS;

            if(view.getMenu(2).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                gameState = SCORES;

            if(view.getMenu(3).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                gameState = ENDED;

        }
    }
    view.menuDisplay(window, mouse);


}

void GameManager::caseOptions(sf::RenderWindow& window) {

    sf::Event event;

    while (gameState == GameManager::OPTIONS) {
        optionsActions(window, event);
    }
    update(window);
}

void GameManager::optionsActions(sf::RenderWindow &window, sf::Event &event) {
    {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));
        window.pollEvent(event);
        {
            if (event.type == sf::Event::MouseButtonReleased)
                if (view.getOptions(3).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                    gameState = MENU;

            if (event.type == sf::Event::Closed)
                gameState = ENDED;
            gameLevel(event, mouse);

            if (event.type == sf::Event::MouseButtonPressed)
                if (view.getCheckbox().getGlobalBounds().contains(mouse)) {
                    if (!bordersPenetration)
                        bordersPenetration = true;
                    else
                        bordersPenetration = false;
                }
            view.setOptionsBacklights(mouse, easy, normal, hard, bordersPenetration);
        }
view.optionsDisplay(window);
    }
}

void GameManager::caseOver(sf::RenderWindow &window) {
        sf::Event event;
    while (gameState == GameManager::OVER) {
    overActions(window, event );
    }
    snake.clearSnake();
    isStartPosition = false;
    isFruitGenerated=false;
    fruit.clearGeneratedFoods();
        update(window);
}

void GameManager::overActions(sf::RenderWindow &window, sf::Event &event) {
    while (gameState == GameManager::OVER) {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));

        while (window.pollEvent(event)) {

            view.setOversBacklights(mouse);
            if (event.type == sf::Event::Closed)
                gameState = ENDED;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                gameState = MENU;


            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Left && view.getOvers(2).getGlobalBounds().contains(mouse))
                    gameState = STARTED;

            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Left && view.getOvers(3).getGlobalBounds().contains(mouse))
                    gameState = MENU;
        }
        view.oversDisplay(window);
    }
}

void GameManager::caseBests(sf::RenderWindow &window) {
    sf::Event event;
    while (gameState == GameManager::SCORES) {
        bestsActions(window, event );
    }
    update(window);
}

void GameManager::bestsActions(sf::RenderWindow &window, sf::Event &event) {
    sf::Vector2f mouse(sf::Mouse::getPosition(window));

    window.pollEvent(event);
    {
        if (event.type == sf::Event::MouseButtonReleased)
            if (view.getScores(6).getGlobalBounds().contains(mouse) && event.mouseButton.button == sf::Mouse::Left)
                gameState = MENU;

        if (event.type == sf::Event::Closed)
            gameState = ENDED;


        view.setBestsBacklights(mouse);
    }
    view.bestsDisplay(window);

}

void GameManager::statesSwitch(sf::RenderWindow &window) {
    switch (gameState) {
        case GameManager::MENU:
            caseMenu(window);
            break;
        case GameManager::OPTIONS: {
            caseOptions(window);
            break;
        }

        case GameManager::SCORES:
            caseBests(window);
            break;

        case GameManager::STARTED: {
            snakeDisplay(window);
            caseStarted(window);
            break;
        }

        case GameManager::OVER: {
            caseOver(window);
            break;
        }
        case GameManager::ENDED:
            window.close();
            break;
    }
}

void GameManager::gameLevel(sf::Event &event, sf::Vector2f mouse) {
    if (event.type == sf::Event::MouseButtonReleased)
        if (view.getOptions(4).getGlobalBounds().contains(mouse) &&
            event.mouseButton.button == sf::Mouse::Left) {
            moveInterval = 0.20f;
            easy = true; hard = false; normal = false;
        }

    if (event.type == sf::Event::MouseButtonReleased)
        if (view.getOptions(5).getGlobalBounds().contains(mouse) &&
            event.mouseButton.button == sf::Mouse::Left) {
            moveInterval = 0.1f;
            easy = false; hard = false; normal = true;
        }
    if (event.type == sf::Event::MouseButtonReleased)
        if (view.getOptions(6).getGlobalBounds().contains(mouse) &&
            event.mouseButton.button == sf::Mouse::Left) {
            moveInterval = 0.04f;
            easy = false; hard = true; normal = false;
        }
}

void GameManager::setParameters() {
    if (!areDimensionsSeted)
    {
        setDimensions();
        areDimensionsSeted= true;
    }

    if (!isStartPosition) {
        snake.setStartPosition(board.getXBeginning(),board.getYBeginning(),board.getRows(),board.getColumns());
        score=0;
        view.updateScore(0);
        isStartPosition = true;
    }
}

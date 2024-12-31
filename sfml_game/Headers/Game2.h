//
//  Game2.h
//  sfml_game
//
//  Created by Amirreza on 12/30/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//
#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBall.h"

#include "ResourcePath.hpp"

class Game {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlEvent;
    
    Player player;
    
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;
    int points;
    
    sf::Font font;
    sf::Text guiText;
    
    void initVariables();
    void initWindow();
    void initFont();
    void initText();
public:
    // Constructor and destructor
    Game();
    virtual ~Game();
    
    // Accessors
    const bool& getEndGame() const;
    
    // Modifiers
    
    // Functions
    const bool running() const;
    void pollEvents();
    
    void spawnSwagBalls();
    const int randomizeType();
    void updatePlayer();
    void updateCollision();
    void updateGui();
    void update();
    void renderGui(sf::RenderTarget * target);
    void render();
};

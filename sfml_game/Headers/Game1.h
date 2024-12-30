//
//  Game.h
//  sfml_game
//
//  Created by Amirreza on 12/30/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//
#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include "sstream"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ResourcePath.hpp"

class Game {
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    
    // Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    
    //Resources
    sf::Font font;
    
    //TEXT
    sf::Text uiText;
    
    // Game logic
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    bool endGame;
    
    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    
    //Private functions
    void initFonts();
    void initText();
    void initVariables();
    void initWindow();
    void initEnemies();
    void spawnEnemies();
    void updateEnemies();
public:
    
    Game();
    virtual ~Game();
    
    // Accessors
    const bool running() const;
    const bool getEndGame() const;
    
    // Functions
    void pollEvents();
    
    void update();
    void updateText();
    void updateMousePositions();
    
    void render();
    void renderText(sf::RenderTarget& target);
    void renderEnemies(sf::RenderTarget& target);
};

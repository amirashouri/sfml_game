//
//  Game.cpp
//  sfml_game
//
//  Created by Amirreza on 12/30/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//

/*

#include "Game1.h"

void Game::initVariables() {
    this->window = nullptr;
    this->points = 0;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;
    this->endGame = false;
    this->health = 10;
}

void Game::initWindow() {
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "SFML window", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

Game::Game() {
    this->initVariables();
    this->initFonts();
    this->initText();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

const bool Game::running() const {
    return this->window->isOpen();
}

const bool Game::getEndGame() const {
    return this->endGame;
}

void Game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void Game::initFonts() {
    if (this->font.loadFromFile(resourcePath() + "tuffy.ttf")) {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
    }
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    //this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
//    this->enemy.setOutlineColor(sf::Color::Green);
//    this->enemy.setOutlineThickness(1.f);
}

void Game::spawnEnemies() {
    this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f);
    int type = rand() % 5;
    
    switch (type) {
        case 0:
            this->enemy.setFillColor(sf::Color::Magenta);
            this->enemy.setSize(sf::Vector2f(10.f, 10.f));
            break;
        case 1:
            this->enemy.setFillColor(sf::Color::Blue);
            this->enemy.setSize(sf::Vector2f(30.f, 30.f));
            break;
        case 2:
            this->enemy.setFillColor(sf::Color::Cyan);
            this->enemy.setSize(sf::Vector2f(50.f, 50.f));
            break;
        case 3:
            this->enemy.setFillColor(sf::Color::Red);
            this->enemy.setSize(sf::Vector2f(60.f, 60.f));
            break;
        case 4:
            this->enemy.setFillColor(sf::Color::Green);
            this->enemy.setSize(sf::Vector2f(70.f, 70.f));
            break;
        default:
            this->enemy.setFillColor(sf::Color::Yellow);
            this->enemy.setSize(sf::Vector2f(70.f, 70.f));
            break;
    }
    
    this->enemies.push_back(this->enemy);
}

void Game::updateText() {
    std::stringstream ss;
    ss << "Points: " << this->points << "\n" << "health: " << this->health;
    this->uiText.setString(ss.str());
}

void Game::update() {
    this->pollEvents();
    if (this->endGame == false) {
        this->updateMousePositions();
        this->updateText();
        this->updateEnemies();
    }
    
    // END GAME
    if (this->health <= 0) {
        this->endGame = true;
    }
}

void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies) {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->spawnEnemies();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }
    
    // Moving and updating the enemies
    for (int i = 0; i < enemies.size(); i++) {
        this->enemies[i].move(0.f, 4.f);
        
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
        }
    }
    
    //Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->mouseHeld == false) {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    
                    if (this->enemies[i].getFillColor() == sf::Color::Magenta)
                        this->points += 10;
                    else if (this->enemies[i].getFillColor() == sf::Color::Blue)
                        this->points += 7;
                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
                        this->points += 5;
                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                        this->points += 3;
                    else
                        this->points += 1;
                    
                    // Delete enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                }
            }
        }
    } else {
        this->mouseHeld = false;
    }
}

void Game::renderText(sf::RenderTarget& target) {
    target.draw(this->uiText);
}

void Game::renderEnemies(sf::RenderTarget& target) {
    for (auto e : this->enemies) {
        target.draw(e);
    }
}

void Game::render() {
    this->window->clear();
    this->renderEnemies(*this->window);
    this->renderText(*this->window);
    this->window->display();
}
*/

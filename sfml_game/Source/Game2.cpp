//
//  Game2.cpp
//  sfml_game
//
//  Created by Amirreza on 12/30/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//
#include <sstream>

#include "Game2.h"

void Game::initVariables() {
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
    this->points = 0;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::initFont() {
    if (this->font.loadFromFile(resourcePath() + "tuffy.ttf")) {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
    }
}

void Game::initText() {
    this->guiText.setFont(this->font);
    this->guiText.setCharacterSize(24);
    this->guiText.setFillColor(sf::Color::White);
}

// Constructor and destructor

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initFont();
    this->initText();
}

Game::~Game() {
    delete this->window;
}

// Accessors

const bool Game::running() const {
    return this->window->isOpen() && this->endGame == false;
}

const int Game::randomizeType() {
    int type = SwagBallTypes::DEFAULT;
    int randValue = rand() % 100 + 1;
    if (randValue > 60 && randValue <= 80)
        type = SwagBallTypes::DAMAGING;
    else if (randValue > 80 && randValue <= 100)
        type = SwagBallTypes::HEALING;
    return type;
}

const bool& Game::getEndGame() const {
    return this->endGame;
}

// Functions
void Game::pollEvents() {
    while (this->window->pollEvent(this->sfmlEvent)) {
        switch (this->sfmlEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
            default:
                break;
        }
    }
}

void Game::spawnSwagBalls() {
    if (this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else {
        if (this->swagBalls.size() < this->maxSwagBalls) {
            this->swagBalls.push_back(SwagBall(*this->window, this->randomizeType()));
            this->spawnTimer = 0.f;
        }
    }
}

void Game::updatePlayer() {
    this->player.update(this->window);
    
    if (this->player.getHp() <= 0) {
        this->endGame = true;
    }
}

void Game::updateCollision() {
    //check the collision
    for (size_t i = 0; i < this->swagBalls.size(); i++) {
        if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())) {
            switch (this->swagBalls[i].getType()) {
                case SwagBallTypes::DEFAULT:
                    this->points++;
                    break;
                case SwagBallTypes::DAMAGING:
                    this->player.takeDamage(1);
                    break;
                case SwagBallTypes::HEALING:
                    this->player.gainHealth(1);
                    break;
            }
            
            // Remove the ball
            this->swagBalls.erase(this->swagBalls.begin() + i);
            
        }
    }
}

void Game::updateGui() {
    std::stringstream ss;
    ss << "Points: " << this->points << "\n" << " - Health: " << this->player.getHp() << " / " << this->player.getHpMax() << "\n";
    this->guiText.setString(ss.str());
}

void Game::update() {
    this->pollEvents();
    
    this->spawnSwagBalls();
    this->updatePlayer();
    this->updateCollision();
    this->updateGui();
}

void Game::renderGui(sf::RenderTarget * target) {
    target->draw(this->guiText);
}

void Game::render() {
    this->window->clear();
    
    // Render stuff
    this->player.render(this->window);
    
    for(auto i : this->swagBalls) {
        i.render(*this->window);
    }
    
    this->renderGui(this->window);
    
    this->window->display();
}

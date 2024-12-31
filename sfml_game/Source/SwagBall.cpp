//
//  SwagBall.cpp
//  sfml_game
//
//  Created by Amirreza on 12/31/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//

#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window) {
    this->shape.setRadius(static_cast<float>(rand()%10+10));
    sf::Color color;
    switch (this->type) {
        case DEFAULT:
            color = sf::Color::Cyan;
            break;
        case DAMAGING:
            color = sf::Color::Red;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.f);
            break;
        case HEALING:
            color = sf::Color::Green;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.f);
            break;
    }
    
    this->shape.setFillColor(color);
    this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x-this->shape.getGlobalBounds().width), static_cast<float>(rand() % window.getSize().y-this->shape.getGlobalBounds().height)));
}

SwagBall::SwagBall(const sf::RenderWindow& widnow, int type) : type(type) {
    this->initShape(widnow);
}

SwagBall::~SwagBall() {}

const sf::CircleShape SwagBall::getShape() const {
    return  this->shape;
}

const int & SwagBall::getType() const {
    return this->type;
}

void SwagBall::update() {}

void SwagBall::render(sf::RenderTarget & target) {
    target.draw(this->shape);
}

//
//  Untitled.swift
//  sfml_game
//
//  Created by Amirreza on 12/31/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player {
private:
    sf::RectangleShape shape;
    
    float movementSpeed;
    int hp;
    int hpMax;
    
    void initVariables();
    void initShape();
    
public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();
    
    // Accessors
    const sf::RectangleShape& getShape() const;
    const int& getHp() const;
    const int& getHpMax() const;
    
    // Functions
    void takeDamage(const int damage);
    void gainHealth(const int health);
    
    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

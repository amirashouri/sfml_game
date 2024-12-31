//
//  SwagBall.hpp
//  sfml_game
//
//  Created by Amirreza on 12/31/24.
//  Copyright © 2024 Amirreza. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum SwagBallTypes { DEFAULT = 0, DAMAGING, HEALING, NROFTYPES };

class SwagBall {
private:
    sf::CircleShape shape;
    int type;
    
    void initShape(const sf::RenderWindow& widnow);
    
public:
    SwagBall(const sf::RenderWindow& widnow, int type);
    virtual ~SwagBall();
    
    // Accessor
    const sf::CircleShape getShape() const;
    const int& getType() const;
    
    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

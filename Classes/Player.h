#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    /* data */

    // Animation

    // Phisics

    // Movement

    // Private Methods
    void initPrivateVariables();

public:
    // Contruct / Destruct
    Player(/* args */);
    ~Player();

    // Accessors

    // Modifiers

    // Public Methods
    void update();
    void render(sf::RenderTarget &target);
};

#endif // __PLAYER_H__
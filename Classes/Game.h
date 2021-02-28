#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "Player.h"

/*
    Class Game that acts as the game engine.
    Wrapper class
*/

class Game
{
private:
    /* data */
    sf::RenderWindow *window;

    sf::Clock dtClock;
    float dt;

    // Private functions
    void initPrivateFunctions();
    void initWindow();

    // initVariables
    void initPlayer();

    // Player
    Player *player;

public:
    // Contructor
    Game();
    // Destructor
    ~Game();

    // Modifiers

    // Acessors

    // Function
    void updadeDt();

    void renderPlayer();
    
    void run();
    void updateSFMLEvents();
    void update();
    void render();
};

#endif // GAME_H
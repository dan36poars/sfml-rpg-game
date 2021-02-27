#ifndef GAME_H
#define GAME_H

// standard library
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <map>
#include <vector>

// sfml libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

/*
    Class Game that acts as the game engine.
    Wrapper class
*/

#define WIDTH_ 800
#define HEIGHT_ 600
#define FRAME_RATE_LIMIT 60

class Game
{
private:
    /* data */
    sf::RenderWindow *window;
    std::string title;

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
    Game(std::string title);
    // Destructor
    ~Game();

    // Modifiers

    // Acessors

    // Function
    void renderPlayer();
    
    void run();
    void updatePoolEvents();
    void update();
    void render();
};

#endif // GAME_H
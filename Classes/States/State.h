#ifndef __STATE_H__
#define __STATE_H__

// standard library
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <stack>

// sfml libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State
{
private:
    /* data */
    sf::RenderWindow *window;
    std::vector<sf::Texture> textures;

public:
    State(sf::RenderWindow *window);
    virtual ~State();

    virtual void endState() = 0;

    // functions
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif // __STATE_H__
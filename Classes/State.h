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
    std::vector<sf::Texture> textures;

public:
    State(/* args */);
    virtual ~State();

    // functions
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // __STATE_H__
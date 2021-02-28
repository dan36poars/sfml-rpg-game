#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

// functions
void GameState::update(const float &dt)
{
    std::cout << "Hello from GameState Class" << std::endl;
}

void GameState::render(sf::RenderTarget *target)
{
}

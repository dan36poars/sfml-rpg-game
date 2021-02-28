#include "Game.h"

// Contructor
Game::Game()
{
    this->initPrivateFunctions();
}

Game::Game(std::string title = "title game") : title(title)
{
    this->initPrivateFunctions();
}

// Destructor
Game::~Game()
{
    delete this->window;
    delete this->player;
}

// Private Functions
void Game::initPrivateFunctions()
{
    this->initWindow();
    this->initPlayer();
}

void Game::initWindow()
{
    // create a sfml window from a window.ini file
    this->window = new sf::RenderWindow(sf::VideoMode(WIDTH_, HEIGHT_), title, sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(FRAME_RATE_LIMIT);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
    this->player = new Player();
}

// Modifiers

// Acessors

// Function
void Game::renderPlayer()
{
    this->player->render(*this->window);
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::updateSFMLEvents()
{
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            this->window->close();

        if (sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    // Drawing some stuffs!

    this->window->display();
}

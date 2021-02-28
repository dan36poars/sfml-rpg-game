#include "Game.h"

// Contructor
Game::Game()
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
    std::ifstream ifs("config/window.ini");

    std::string title = "nome";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limite = 60;
    bool verticalsync_enable = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limite;
        ifs >> verticalsync_enable;        
    }
    
    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(framerate_limite);
    this->window->setVerticalSyncEnabled(verticalsync_enable);
}

void Game::initPlayer()
{
    this->player = new Player();
}

// Modifiers

// Acessors

// Function
void Game::updadeDt() 
{
    // as many more process in the game increases the Dt time
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::renderPlayer()
{
    this->player->render(*this->window);
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updadeDt();
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

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

    // delete the states from stack
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    
}

// Private Functions
void Game::initPrivateFunctions()
{
    this->initWindow();
    this->initStates();
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

// initVariables
void Game::initPlayer()
{
    this->player = new Player();
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
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
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
    }
}

void Game::render()
{
    this->window->clear();

    // Drawing some stuffs!
    if (!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}

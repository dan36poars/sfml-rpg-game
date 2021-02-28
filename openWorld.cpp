#include "Classes/Game.h"

int main(int argc, char const *argv[])
{
    /* code */
    std::srand((unsigned)time(0));
    Game game;
    game.run();
    return 0;
}

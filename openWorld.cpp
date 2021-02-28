#include "Classes/Game.h"

int main(int argc, char const *argv[])
{
    /* code */
    std::srand((unsigned)time(0));
    Game game("OpenWorld Game RPG");
    game.run();
    return 0;
}

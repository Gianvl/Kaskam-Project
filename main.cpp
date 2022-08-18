#include "Game.h"

int main()
{
    Game game;

    while(game.getPlaying() == true)
    {
        game.play();
    }

    cout << "BYE BYE" << endl;

    return 0;
}

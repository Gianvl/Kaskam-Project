#ifndef GAME_H
#define GAME_H

#include "Character.h"

class Game
{
    public:

    //CONSTRUCTORS & DESTRUCTORS
        Game();
        virtual ~Game();
    //METODS
        bool getPlaying()const;
        void play();
        void setCharacter();
        int menu()const;

        void travel();
        void battle();
        //void fight(const Enemy* x);
        void event();
        void shop();
        void boss();

        void rest();
        void lore()const;
        void death();

    private:
        bool playing;
        bool newGame;
        int points;
        Character* character;
};

#endif // GAME_H

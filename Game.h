#ifndef GAME_H
#define GAME_H

#include "Character.h"

#include <locale>
#include <cstdlib>
#include <ctime>
#include <random>


class Game
{
    private:
        bool _playing;
        bool _newGame;
        Character* _character;

    public:

    //CONSTRUCTORS & DESTRUCTORS
        Game();
        ~Game(){}

    ///METODS

        //STATIC
        static float normalF(float mid, float desv);

        //COMMON
        inline bool getPlaying()const {return _playing;}
        void play();
        void setCharacter();
        int menu()const;
        void lore()const;
        void death();

        int clasSpeach()const;
        char sexSpeach()const;

};

#endif // GAME_H

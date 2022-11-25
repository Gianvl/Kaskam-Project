#include "Armor.h"
#include "Game.h"

Armor::Armor(const string& name, int defense)
: _name(name), _defense(defense)
{}

float Armor::getDef()const
{
    return Game::normalF(_defense, 1.5);
}

void Armor::show()const
{
    cout << "ARMOR: "   << _name      << "\t\t"
         << "DEFENSE: " << _defense   << endl;
}


//KSAK

Ksak::Ksak()
:Armor("K-sa-K", 5.0)
{}


//WIND BREAKER

WindBreaker::WindBreaker()
:Armor("Wind Breaker", 9.0)
{
    _uses = 5;
    _usesMax = 5;
}

float WindBreaker::getDef()
{
    if(_uses <= 0)
    {
        cout << "ARMOR BROKEN!" << endl;
        return 0;
    }
    _uses--;
    return Armor::getDef();
}

void WindBreaker::show()const
{
    Armor::show();
    cout << "USES LEFT: " << _uses << endl;
}


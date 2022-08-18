#include "Armor.h"

Armor::Armor()
{
    //ctor
}

Armor::~Armor()
{
    //dtor
}

void Armor::show()const
{
    cout << "ARMOR: "   << this->name      << endl
         << "DEFENSE: " << this->defense   << endl;
}


//KSAK

Ksak::Ksak()
:Armor()
{
    this->defense = 5;
    this->name = "K-sa-K";
}

int Ksak::getDef()
{
    return this->defense;
}

int Ksak::sell()const
{
    return 0;
}


//WIND BREAKER

windBreaker::windBreaker()
:Armor()
{
    this->defense = 15;
    this->name = "Wind Breaker";
    this->uses = 5;
    this->usesMax = 5;
}

int windBreaker::getDef()
{
    if(this->uses <= 0)
    {
        cout << "ARMOR BROKEN!" << endl;
        return 0;
    }
    this->uses -= 1;
    return defense;
}

void windBreaker::show()const
{
    Armor::show();
    cout << "USES LEFT: " << this->uses << endl;
}

int windBreaker::sell()const
{
    return (uses*5);
}

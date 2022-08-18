#include "Weapon.h"

Weapon::Weapon()
{
    //ctor
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::show()const
{
    cout << "WEAPON: "   << this->name   << endl
         << "DAMAGE: " << this->damage << endl;
}


//HANDS

Hands::Hands()
:Weapon()
{
    this->name = "Hands";
    this->damage = 15;
}

int Hands::getDmg()
{
    return this->damage;
}

int Hands::sell()const
{
    return 0;
}

//MOCHO

Mocho::Mocho()
:Weapon()
{
    this->name = "Mocho";
    this->damage = 50;
    this->uses = 2;
    this->usesMax = 2;
    this->ammo = 0;
    this->ammoMax = 2;
}

int Mocho::getDmg()
{
    if(ammo > 0 && uses > 0)
        return damage;
    else
        cout << (uses <= 0 ? "WEAPON BROKEN!" : "NO AMMO!") << endl;
    return 0;
}

void Mocho::show()const
{
    Weapon::show();
    cout << "AMMO: " << this->ammo << endl;
    cout << "USES LEFT: ";
    cout << (uses < 0 ? 0 : uses)  << endl;
}

int Mocho::sell()const
{
    return (uses*10) + (ammo* 5);
}

//SWORD OF ARUOR

swordOfAruzor::swordOfAruzor()
:Weapon()
{
    this->name = "Sword Of Aruzor";
    this->damage = 40;
    this->uses = 5;
    this->usesMax = 5;
}

int swordOfAruzor::getDmg()
{
    if(uses <= 0)
    {
        cout << "WEAPON BROKEN!" << endl;
        return 0;
    }
    this->uses -= 1;
    return this->damage;
}

void swordOfAruzor::show()const
{
    Weapon::show();
    cout << "USES LEFT: ";
    cout << (uses <= 0 ? 0 : uses) << endl;
}

int swordOfAruzor::sell()const
{
    return (uses*5);
}


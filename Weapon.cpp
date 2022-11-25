#include "Weapon.h"
#include "Game.h"

Weapon::Weapon(const string& name, int damage)
:_name(name), _damage(damage)
{}

//STATIC

Weapon* Weapon::weaponDrop();
{

}

float Weapon::getDmg()const
{
    return Game::normalF(_damage, 3.3);
}

void Weapon::show()const
{
    cout << "WEAPON: "   << _name      << "\t\t"
         << "DAMAGE: "   << _damage    << endl;
}


//HANDS

Hands::Hands()
:Weapon("Hands", 10.0)
{}

//MOCHO

Mocho::Mocho()
:Weapon("Mocho", 42.0)
{
    _uses = 2;
    _usesMax = 2;
    _ammo = 0;
    _ammoMax = 2;
}

float Mocho::getDmg()
{
    if(_ammo > 0 && _uses > 0)
    {
        _uses--;
        _ammo--;
        return Weapon::getDmg();
    }

    else
        cout << (_uses <= 0 ? "WEAPON BROKEN!" : "NO AMMO!") << endl;
    return 0;
}

void Mocho::show()const
{
    Weapon::show();
    cout << "AMMO: "      << _ammo  << "\t\t";
    cout << "USES LEFT: " << _uses  << endl;
}


//SWORD OF ARUZOR

swordOfAruzor::swordOfAruzor()
:Weapon("Sword Of Aruzor", 32.0)
{
    _uses = 5;
    _usesMax = 5;
}

float swordOfAruzor::getDmg()
{
    if(_uses <= 0)
    {
        cout << "WEAPON BROKEN!" << endl;
        return 0;
    }
    _uses--;
    return Weapon::getDmg();
}

void swordOfAruzor::show()const
{
    Weapon::show();
    cout << "USES LEFT: " << _uses << endl;
}


//KaskOT

KaskOT::KaskOT()
:Weapon("Kask-OT", 18.5)
{
    _uses = 3;
    _usesMax = 5;
}

float KaskOT::getDmg()
{
    if(_uses > 0)
    {
        _uses--;
        return Weapon::getDmg();
    }

    cout << "NO AMMO" << endl;
    return 0;
}

void KaskOT::show()const
{
    Weapon::show();
    cout << "USES LEFT: " << _uses << endl;
}

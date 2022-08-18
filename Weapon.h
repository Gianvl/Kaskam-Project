#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Weapon
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Weapon();
        virtual ~Weapon();

        //METODS
        virtual int getDmg() = 0;
        virtual void show()const;
        virtual int sell()const = 0;

    protected:
        int damage;
        string name;

};



class Hands : public Weapon
{
    public:
        //CONSTRUCTORS
        Hands();

        //METODS
        int getDmg();
        int sell()const;
  };

class Mocho : public Weapon
{
    public:
        //CONSTRUCTORS
        Mocho();

        //METODS
        int getDmg();
        void show()const;
        int sell()const;

    private:
        int uses;
        int usesMax;
        int ammo;
        int ammoMax;
};

class swordOfAruzor : public Weapon
{
    public:
        //CONSTRUCTORS
        swordOfAruzor();

        //METODS
        int getDmg();
        void show()const;
        int sell()const;

    private:
        int uses;
        int usesMax;
};

/*class KaskOT : public Weapon
{
    public:
        //CONSTRUCTORS
        KaskOT();
};*/

#endif // WEAPON_H

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Weapon(const string& name, int damage);
        virtual inline ~Weapon(){}

        //STATIC
        static Weapon* weaponDrop();

        //METODS
        virtual float getDmg()const;
        virtual void show()const;
        virtual int sell()const = 0;

    protected:
        string _name;
        float _damage;

};


///WEAPONS

//HANDS
class Hands : public Weapon
{
    public:
        //CONSTRUCTORS
        Hands();
        inline ~Hands(){}

        //METODS
        inline int sell()const {return 0;}

  };

//MOCHO
class Mocho : public Weapon
{
    public:
        //CONSTRUCTORS
        Mocho();
        inline ~Mocho(){}

        //METODS
        float getDmg();
        void show()const;
        inline int sell()const{return (_uses*10) + (_ammo* 5);}

    private:
        int _uses;
        int _usesMax;
        int _ammo;
        int _ammoMax;
};

//SWORD OF ARUZOR
class swordOfAruzor : public Weapon
{
    public:
        //CONSTRUCTORS
        swordOfAruzor();
        inline ~swordOfAruzor(){}

        //METODS
        float getDmg();
        void show()const;
        inline int sell()const{return (_uses*5);}

    private:
        int _uses;
        int _usesMax;
};

//KASKOT
class KaskOT : public Weapon
{
    public:
        //CONSTRUCTORS
        KaskOT();
        inline ~KaskOT(){}

        //METODS
        float getDmg();
        void show()const;
        inline int sell()const{return (_uses*1);}

    private:
        int _uses;
        int _usesMax;

};

#endif // WEAPON_H

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armor.h"

class Character
{
    public:

        // CONSTRUCTORS & DESTRUCTORS
        Character(const string& name, const char sex);
        virtual ~Character();

        // METODS
        void show()const;
        char getSex()const;
        int getFights()const;

        int attack();
        void defend(int dmg);
        void hurt(int dmg);
        int getLife()const;
        void heal(int lp);
        void energyUp(int ep);
        void exhaust(int ep);
        virtual int smoke();
        virtual int drink();
        int getSmarfon();
        int getQuenquen();

        virtual int pay(int gold);
        virtual void buyQuenquen();
        virtual void buySmarfon();
        virtual void buyWeapon(Weapon* wp);
        virtual void buyArmor(Armor* ar);
        virtual void sellWeapon();
        virtual void sellArmor();

        //FRIENDS
        friend class Game;


    protected:
        string name;
        char sex;
        string className;
        Weapon* weapon;
        Armor* armor;
        int fights;
        int life;
        int lifeMax;
        int stamina;
        int staminaMax;
        int quenquens;
        int quenquensMax;
        int smarfons;
        int smarfonsMax;
        int gold;

};

//CLASSES

/*class Soul : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Soul(const string& name, const char sex);
};*/

class Kaskam : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Kaskam(const string& name, const char sex);

        //METODS
        int smoke();

};

class Cristian : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Cristian(const string& name, const char sex);

        //METODS
        int drink();
};

class Human : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Human(const string& name, const char sex);

};



#endif // CHARACTER_H

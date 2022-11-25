#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armor.h"
#include "Enemy.h"

class Character
{
    private:
        string _name;
        char _sex;

    protected:
        string _className;
        Weapon* _weapon;
        Armor* _armor;
        int _fights;
        int _life;
        int _lifeMax;
        int _stamina;
        int _staminaMax;
        int _kenkens;
        int _kenkensMax;
        int _smarfons;
        int _smarfonsMax;
        int _gold;
        int _points;

    public:

        ///CONSTRUCTORS & DESTRUCTORS
        Character(const string& name, const char sex);
        virtual inline ~Character(){}

        ///METODS

        //COMMONS
        void show()const;
        void travel();
        void event();
        void rest();
        //FIGHTS
        void battle(Enemy* en);
        void yourTurn(Enemy* en);
        //void boss();
        Enemy* enemyGen()const;
        //SHOP
        void shop();
        int shopSpeach()const;
        Armor* armorStock()const;
        Weapon* weaponStock()const;

        //UTILITIES
        inline char getSex()const {return _sex;}
        inline int getFights()const {return _fights;}
        inline int getLife()const {return _life;}
        inline float attack(){return _weapon->getDmg();}
        void defend(float dmg);
        void inline hurt(float dmg)
        {cout << "FUCKKK!!" << endl; _life -= dmg;}
        void heal(int lp);
        void energyUp(int ep);
        void exhaust(int ep);
        virtual int smoke();
        virtual int drink();
        int getSmarfon();
        int getKenken();
        int inline gold()const{return _gold;}
        int pay(int gold);
        void buyKenken();
        void buySmarfon();
        void buyWeapon(Weapon* wp);
        void buyArmor(Armor* ar);
        void sellWeapon();
        void sellArmor();
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
        inline ~Kaskam(){}

        //METODS
        int smoke();

};

class Cristian : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Cristian(const string& name, const char sex);
        inline ~Cristian(){}

        //METODS
        int drink();
};

class Human : public Character
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Human(const string& name, const char sex);
        inline ~Human(){}

};



#endif // CHARACTER_H

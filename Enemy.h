#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>

using namespace std;

class Enemy
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Enemy(const string& name, int life, float damage, float defense,
              int points, int gold);
        virtual inline ~Enemy(){}

        //METODS
        virtual void defend(float dmg);
        virtual float attack()const;
        virtual inline void hurt(float dmg){_life-=dmg;}
        inline int life()const{return _life;}
        inline int getPoints()const{return _points;}
        inline int getGold()const{return _gold;}

    protected:
        string _name;
        int _life;
        int _lifeMax;
        float _damage;
        float _defense;
        int _points;
        int _gold;
};


//ENEMIES

class Karkaram : public Enemy
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Karkaram();
        inline ~Karkaram(){}

        //METODS
        inline void hurt(float dmg)
        {cout << "SON OF A BITCH!!" << endl; Enemy::hurt(dmg);}
};

class Punga : public Enemy
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Punga();
        inline ~Punga(){}

        //METODS
        inline void hurt(float dmg)
        {cout << "RESCATETER!!" << endl; Enemy::hurt(dmg);}
};

#endif // ENEMY_H

#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include <iostream>

using namespace std;

class Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Armor(const string& name, int defense);
        virtual inline ~Armor(){}

        //STATIC
        static Armor* armorDrop();

        //METODS
        virtual float getDef()const;
        virtual void show()const;
        virtual int sell()const = 0;

    protected:
        string _name;
        float _defense;

};


///ARMORS

//K-SA-K
class Ksak : public Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Ksak();
        inline ~Ksak(){}


        //METODS
        inline int sell()const {return 0;}

};

//WIND BREAKER
class WindBreaker : public Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        WindBreaker();
        inline ~WindBreaker(){}

        //METODS
        float getDef();
        void show()const;
        inline int sell()const {return _uses*5;}

    private:
        int _uses;
        int _usesMax;
};


#endif // ARMOR_H

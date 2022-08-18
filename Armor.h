#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Armor();
        virtual ~Armor();

        //METODS
        virtual int getDef() = 0;
        virtual void show()const;
        virtual int sell()const = 0;

    protected:
        int defense;
        string name;

};

//ARMORS

class Ksak : public Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Ksak();

        //METODS
        int getDef();
        int sell()const;

};

class windBreaker : public Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        windBreaker();

        //METODS
        int getDef();
        void show()const;
        int sell()const;

    private:
        int uses;
        int usesMax;
};

/*class  : public Armor
{
    public:
        //CONSTRUCTORS & DESTRUCTORS
        Casaca();

        //METODS
        int getDef();

    private:
        int uses;
        int usesMax;
};*/

#endif // ARMOR_H

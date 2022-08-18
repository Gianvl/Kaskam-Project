#include "Character.h"

Character::Character(const string& name, const char sex)
{
    this->name = name;
    this->sex = sex;
    this->weapon = new Hands();
    this->armor = new Ksak();
    this->fights = 0;
    this->gold = 10;
}

Character::~Character()
{
    //dtor
}

void Character::show()const
{
    cout << "NAME:  "     << name      << endl
         << "SEX:  "      << sex       << endl
         << "CLASS: "     << className << endl;
         weapon->show();
         armor->show();
    cout << "FIGHTS: "      << fights  << endl
         << "LIFE: "        << life    << endl
         << "LIFE MAX: "    << lifeMax << endl
         << "STAMINA: "     << stamina << endl
         << "QUENQUENS: "   << quenquens  << endl
         << "SMARFONS: "    << smarfons   << endl
         << "GOLD: "        << gold    << endl;
}

char Character::getSex()const
{
    return this->sex;
}

int Character::getFights()const
{
    return this->fights;
}

int Character::attack()
{
    return weapon->getDmg();
}

void Character::defend(int dmg)
{
    int realDmg = dmg - armor->getDef();
    this->life -= (realDmg <= 0 ? 0 : realDmg);

}

void Character::hurt(int dmg)
{
    int realDmg = life - dmg;
    this->life = (realDmg <= 0 ? 0 : realDmg);
}

void Character::heal(int lp)
{
    int realLife = life+lp;
    this->life = (realLife >= lifeMax ? lifeMax : realLife);
}

int Character::getLife()const
{
    return this->life;
}

void Character::exhaust(int ep)
{
   int realEne = stamina - ep;
   this->stamina = (realEne <= 0 ? 0 : realEne);
}

void Character::energyUp(int ep)
{
    int realSta = stamina+ep;
    this->stamina = (realSta >= staminaMax ? staminaMax : realSta);
}

int Character::smoke()
{
    if(quenquens <= 0)
    {
        cout << "WHAT A MASK DO I HAVE..." << endl;
        return 0;
    }
    cout << "RICHARD" << '"' << "THE RICH" << "RICHARSON!" << endl;
    this->quenquens -= 1;
    heal(30);
    exhaust(2);
    return 1;
}

int Character::drink()
{
    if(smarfons <= 0)
    {
        cout << "I GOT THIS DANGEROUS THIRST..." << endl;
        return 0;
    }
    cout << "TILL THE LAST DROP!" << endl;
    this->smarfons -= 1;
    energyUp(2);
    hurt(10);
    return 1;
}

int Character::getSmarfon()
{
    if(smarfons == smarfonsMax)
    {
        cout << "NO SPACE!" << endl;
        return 0;
    }
    return 1;
}

int Character::getQuenquen()
{
    if(quenquens == quenquensMax)
    {
        cout << "NO SPACE" << endl;
        return 0;
    }
    return 1;
}

void Character::buyQuenquen()
{
    if(!getQuenquen())
        return;
    if(pay(10))
        this->quenquens += 1;
}

void Character::buySmarfon()
{
    if(!getSmarfon())
        return;
    if(pay(10))
        this->smarfons += 1;
}

void Character::buyWeapon(Weapon* wp)
{
    if(!pay(gold))
        return;
    delete this->weapon;
    this->weapon = wp;
}

void Character::buyArmor(Armor* ar)
{
    if(!pay(gold))
        return;
    delete this->armor;
    this->armor = ar;
}

int Character::pay(int gold)
{
    int realGold = gold-gold;
    if(realGold >= 0)
    {
        this->gold = realGold;
        return 1;
    }
    return 0;
}

void Character::sellWeapon()
{
    this->gold += this->weapon->sell();
    delete this->weapon;
    this->weapon = new Hands();
}

void Character::sellArmor()
{
    this->gold += this->armor->sell();
    delete this->armor;
    this->armor = new Ksak();
}


/*// SOUL

Soul::Soul(const string& name, const char sex)
:Character(name, sex)
{
    this->className = "Soul";
    this->life = this->lifeMax = 1;
    this->stamina = this->staminaMax = 10;
    this->quenquens = this->quenquensMax = 0;
    this->smarfons = this->smarfonsMax = 0;
}*/

// KASKAM

Kaskam::Kaskam(const string& name, const char sex)
:Character(name, sex)
{
    this->className = "Kaskam";
    this->life = this->lifeMax = 80;
    this->stamina = this->staminaMax = 8;
    this->quenquens = this->quenquensMax = 2;
    this->smarfons = this->smarfonsMax = 1;
}

int Kaskam::smoke()
{
    if(!Character::smoke())
        return 0;
    Character::heal(10);
    cout << "KAS-KAS-KAS" << endl;
    return 1;
}


//CRISTIAN

Cristian::Cristian(const string& name, const char sex)
:Character(name, sex)
{
    this->className = "Cristian";
    this->life = this->lifeMax = 70;
    this->stamina = this->staminaMax = 9;
    this->quenquens = this->quenquensMax = 0;
    this->smarfons = this->smarfonsMax = 2;
    this->gold += 5;
}

int Cristian::drink()
{
    if(!Character::drink())
        return 0;
    cout << "YAMPEIN!" << endl;
    Character::heal(10);
    return 1;
}


//HUMAN

Human::Human(const string& name, const char sex)
:Character(name, sex)
{
    this->className = "Human";
    this->life = this->lifeMax = 80;
    this->stamina = this->staminaMax = 9;
    this->quenquens = this->quenquensMax = 2;
    this->smarfons = this->smarfonsMax = 1;
}





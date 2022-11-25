#include "Character.h"
#include "Game.h"

Character::Character(const string& name, const char sex)
: _name(name), _sex(sex), _fights(0), _gold(10), _points(0)
{
    _weapon = new Hands();
    _armor = new Ksak();
}

///METODS

void Character::travel()
{
    ///EVENT, FIGHT, SHOP, BOSS
    int i = rand()%5;

    switch(i)
    {
        case 0:
            battle(enemyGen());
            break;
        case 1:
            event();
            break;
        case 2:
            shop();
            break;
        case 3:
            cout << "NOT YET!" << endl;
            //boss();
            break;
        case 4:
            if(_fights && !_fights%3)
                rest();
            else
            {
                cout << "I JUST KEEP WALKING..."      << endl
                     << "THE SUN IS ABOVE MY HEAD..." << endl;
                system("pause");
            }
            break;
    }
}

Enemy* Character::enemyGen()const
{
    Enemy* en = NULL;
    float i = Game::normalF(10.0, 3.3);

    if(i < 3.3 || i > 16.2)
    {
        switch(rand()%2)
        {
            case 0:
                en = new Punga();
            case 1:
                en = new Karkaram();
        }
    }
    else
    {
        switch(rand()%2)
        {
            case 0:
                en = new Punga();
            case 1:
                en = new Karkaram();
        }
    }
    return en;
}

void Character::battle(Enemy* en)
{
    int i = 1;
    system("cls");
    cout << "A TRAP! PREPARE FOR THE BATTLE!" << endl;

    while(en->life() > 0 && this->_life > 0)
    {
        cout << "ROUND "  << '"' << i << '"' << endl << endl;
        yourTurn(en);

        if(en->life() <= 0)
        {
            cout <<  endl << "ENEMY DEATH!" << endl << endl;
            _points+= en->getPoints();
            _gold += en->getGold();
            cout << "POINTS: " << _points << endl
                 << "GOLD: "   << _gold   << endl << endl
                 << "ROUNDS: " << i << endl;
            ///REWARD??
        }
        else
        {
            cout << "ENEMY ATTACKING!" << endl;
            defend(en->attack());
        }
        system("pause");
        system("cls");
        i++;
    }
    delete en;
}

void Character::yourTurn(Enemy* en)
{
    int i;
    cout << "1: ATTACK"  << "\t\t\t" << "Life: "     << _life     << endl
         << "2: DRINK"   << "\t\t\t" << "Stamina: "  << _stamina  << endl
         << "3: SMOKE"   << "\t\t\t" << "Kenkens: "  << _kenkens  << endl
         << "\t\t\t\t"   << "Smarfons: " << _smarfons << endl << endl;
    cin >> i;
    while(i<1 || i>3)
    {
        system("cls");
        cout << "WHAT! COME ON MAN, WE ARE FIGHTING!" << endl << endl
             << "1: ATTACK" << "\t\t\t" << "Life: "     << _life     << endl
             << "2: DRINK"  << "\t\t\t" << "Stamina: "  << _stamina  << endl
             << "3: SMOKE"  << "\t\t\t" << "Kenkens: "  << _kenkens  << endl
             << "\t\t\t\t"  << "Smarfons: " << _smarfons << endl << endl;
        cin >> i;
    }

    switch(i)
    {
        case 1:
            en->defend(attack());
            break;
        case 2:
            drink();
            break;
        case 3:
            smoke();
            break;
    }
 }

void Character::event()
{
    int i = rand()%3;
    cout << "WHAT NOW?..." << endl << endl;
    switch(i)
    {
        case 0:
            cout << "WHATS UP BUDDY, I SMELT YA!" << endl;
            _kenkens = 0;
            break;
        case 1:
            cout << "*MOVING HER HEAD* THROW THAT! THROW THAT!" << endl;
            _smarfons = 0;
            break;
        case 2:
            cout << "WOF-WOF-WOF" << endl;
            cout << "What a nice company you have found, very lucky..." << endl;
            ///NOT DECIDED///
            break;
    }
}

void Character::shop()
{
    int i;
    cout << "A CAMP..." << endl;
    system("pause");
    cout << "TELL ME, WHAT CAN I DO FOR YOU?" << endl << endl;
    i = shopSpeach();

    if(i!=0)
    {
        while(i < 0|| i > 6)
        {
            system("cls");
            cout << "WHAT? SPEAK MY LENGUAGE!" << endl << endl;
            i = shopSpeach();
        }
        switch(i)
        {
            case 0:
                break;
            case 1:
                buyKenken();
                break;
            case 2:
                buySmarfon();
                break;
            case 3:
                //buyWeapon(weaponStock());
                break;
            case 4:
                //buyArmor(armorStock());
                break;
            case 5:
                sellWeapon();
                break;
            case 6:
                sellArmor();
                break;
        }
    }
    cout << "SEE YA SOON..." << endl << endl;
    system("pause");
    system("cls");
}

int Character::shopSpeach()const
{
    int i;
    cout << "\t\tMY GOLD: " << _gold << endl;
    cout << "1: BUY KENKEN ($10)"    << endl
         << "2: BUY SMARFON ($10)"   << endl
         << "3: BUY WEAPON"   << endl
         << "4: BUY ARMOR"    << endl
         << "5: SELL WEAPON"  << endl
         << "6: SELL ARMOR"   << endl
         << "0: EXIT"         << endl;
    cin >> i;
    return i;
}

void Character::rest()
{
    system("cls");
    cout << "THIS PLACE IS GOOD ENOUGH, I DESERVE A REST..." << endl;
    system("pause");
    cout << "OK, LETS GO AGAIN!" << endl;
    heal(10);
    energyUp(5);
    system("pause");
}

void Character::show()const
{
    cout << "NAME: "      << _name      << "\t"
         << "SEX: "       << _sex       << "\t"
         << "CLASS: "     << _className  << endl << endl;
         _weapon->show();
         _armor->show();
    cout << "FIGHTS: "      << _fights   << endl << endl
         << "LIFE: "        << _life     << "\t\t"
         << "LIFE MAX: "    << _lifeMax  << endl
         << "STAMINA: "     << _stamina  << "\t\t"
         << "STAMINA MAX: " << _staminaMax    << endl
         << "QUENQUENS: "   << _kenkens  << "\t\t"
         << "QUENQUENS MAX: " << _kenkensMax  << endl
         << "SMARFONS: "    << _smarfons << "\t\t"
         << "SMARFONS MAX: "  << _smarfonsMax << endl
         << "GOLD: "        << _gold     << endl << endl;

    system("pause");
    system("cls");
}


///UTILITIES


void Character::defend(float dmg)
{
    int realDmg = dmg - _armor->getDef();
    _life -= (realDmg > 0 ? realDmg : 0);
    cout << "DAMAGE TAKEN: " << realDmg << endl;
}

void Character::heal(int lp)
{
    int realLife = _life + lp;
    _life = (realLife >= _lifeMax ? _lifeMax : realLife);
}

void Character::exhaust(int ep)
{
   int realEne = _stamina - ep;
   _stamina = (realEne <= 0 ? 0 : realEne);
}

void Character::energyUp(int ep)
{
    int realSta = _stamina + ep;
    _stamina = (realSta >= _staminaMax ? _staminaMax : realSta);
}

int Character::smoke()
{
    if(_kenkens <= 0)
    {
        cout << "WHAT A MASK DO I HAVE..." << endl;
        return 0;
    }
    cout << "RICHARD " << '"' << "THE RICH" << '"' << " RICHARDSON!" << endl;
    _kenkens--;
    heal(20);
    exhaust(2);
    system("pause");
    return 1;
}

int Character::drink()
{
    if(_smarfons <= 0)
    {
        cout << "I GOT THIS DANGEROUS THIRST..." << endl;
        return 0;
    }
    cout << "TILL THE LAST DROP!" << endl;
    _smarfons--;
    energyUp(2);
    hurt(10);
    system("pause");
    return 1;
}



int Character::getSmarfon()
{
    if(_smarfons == _smarfonsMax)
    {
        cout << "NO SPACE!" << endl;
        return 0;
    }
    return 1;
}

int Character::getKenken()
{
    if(_kenkens == _kenkensMax)
    {
        cout << "NO SPACE" << endl;
        return 0;
    }
    return 1;
}

void Character::buyKenken()
{
    if(!getKenken())
        return;
    if(pay(10))
        _kenkens++;
}

void Character::buySmarfon()
{
    if(!getSmarfon())
        return;
    if(pay(10))
        _smarfons++;
}

void Character::buyWeapon(Weapon* wp)
{
    if(!pay(wp->sell()+5))
        return;
    delete _weapon;
    _weapon = wp;
}

void Character::buyArmor(Armor* ar)
{
    if(!pay(ar->sell()+5))
        return;
    delete _armor;
    _armor = ar;
}

int Character::pay(int gold)
{
    int realGold = _gold - gold;
    if(realGold >= 0)
    {
        cout << "CONSUME CONSUME CONSUME" << endl;
        _gold = realGold;
        return 1;
    }
    cout << "NO MONEYY!" << endl;
    return 0;
}

void Character::sellWeapon()
{
    _gold += _weapon->sell();
    delete _weapon;
    _weapon = new Hands();
}

void Character::sellArmor()
{
    _gold += _armor->sell();
    delete _armor;
    _armor = new Ksak();
}


///--------------------------------------------------------------------------///
///CLASSES


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
    _className = "Kaskam";
    _life = _lifeMax = 80;
    _stamina = _staminaMax = 8;
    _kenkens = _kenkensMax = 2;
    _smarfons = _smarfonsMax = 1;
}

int Kaskam::smoke()
{
    if(!Character::smoke())
        return 0;
    heal(10);
    cout << "KAS-KAS-KAS" << endl;
    return 1;
}


//CRISTIAN

Cristian::Cristian(const string& name, const char sex)
:Character(name, sex)
{
    _className = "Cristian";
    _life = _lifeMax = 70;
    _stamina = _staminaMax = 9;
    _kenkens = _kenkensMax = 0;
    _smarfons = _smarfonsMax = 2;
    _gold += 5;
}

int Cristian::drink()
{
    if(!Character::drink())
        return 0;
    cout << "YAMPEIN!" << endl;
    heal(10);
    return 1;
}


//HUMAN

Human::Human(const string& name, const char sex)
:Character(name, sex)
{
    _className = "Human";
    _life = _lifeMax = 80;
    _stamina = _staminaMax = 9;
    _kenkens = _kenkensMax = 2;
    _smarfons = _smarfonsMax = 1;
}


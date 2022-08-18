#include "Game.h"

Game::Game()
{
    this->playing = true;
    this->newGame = true;
    this->points = 0;
    this->character = NULL;
}

Game::~Game()
{
    //dtor
}

bool Game::getPlaying()const
{
    return this->playing;
}

void Game::play()
{
    int i;
    if(this->newGame == true)
    {
        setCharacter();
        this->newGame = false;
        return;
    }
    else if(character->getLife() > 0)
    {
        i = menu();

        switch(i)
        {
        /*case 1:
                travel();
                break;*/
        case 2:
                rest();
                break;
        /*case 3:
                lore();
                break;*/
        case 4:
                character->show();
                break;
        case 0:
                delete character;
                this->character = NULL;
                this->playing = false;
                break;
        }
        return;
    }

    death();
    return;
}

void Game::setCharacter()
{
    int i;
    string name;
    char sex;

    cout << "WELCOME! CHOOSE YOUR NAME" << endl
         << "-------  ------ ---- ----"  << endl;
    cin >> name;

    cout << "CHOOSE YOUR SEX (M/F)" << endl
         << "------ ---- --- -----"  << endl;
    cin >> sex;

    while(sex != 'M' && sex != 'F')
    {
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl
             << "CHOOSE YOUR SEX (M/F)" << endl
             << "------ ---- --- -----"  << endl;
        cin >> sex;
    }

    cout << "CHOOSE YOUR CLASS" << endl
         << "------ ---- -----"  << endl << endl
         << "1: Kaskam"     << endl
         << "2: Cristian"   << endl
         << "3: Human"     << endl;
    cin >> i;

    while(i < 1 || i > 3)
    {
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl
             << "CHOOSE YOUR CLASS" << endl
             << "------ ---- -----"  << endl << endl
             << "1: Kaskam"     << endl
             << "2: Cristian"   << endl
             << "3: Human"     << endl;
        cin >> i;
    }

    switch(i)
    {
    case 1:
        this->character = new Kaskam(name, sex);
        break;
    case 2:
        this->character = new Cristian(name, sex);
        break;
    case 3:
        this->character = new Human(name, sex);
        break;
    }
}

int Game::menu()const
{
    int i;
    cout << "MENU" << endl
         << "----"  << endl << endl
         << "1: TRAVEL" << endl
         << "2: REST"   << endl
         << "3: LORE"   << endl
         << "4: STATS"  << endl
         << "0: EXIT"   << endl;
    cin >> i;

    while(i < 0 || i > 4)
    {
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl
             << "MENU" << endl
             << "----"  << endl << endl
             << "1: TRAVEL" << endl
             << "2: REST"   << endl
             << "3: LORE"   << endl
             << "4: STATS"  << endl
             << "0: EXIT"   << endl;
        cin >> i;
    }
    return i;
}

void Game::death()
{
    int i;
    delete character;
    this->character = NULL;

    //CLEAR
    cout << "GAME OVER!" << endl
         << "---- ----"  << endl << endl
         << "1: NEW GAME" << endl
         << "0: EXIT" << endl;
    cin >> i;

    while(i < 0 || i > 1)
    {
        //CLEAR
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl
             << "1: NEW GAME" << endl
             << "0: EXIT"     << endl;
        cin >> i;
    }

    switch(i)
    {
    case 1:
            this->newGame = true;
            this->points = 0;
            break;
    case 2:
            this->playing = false;
            break;
    }
}


//TRAVEL

/*void Game::travel()
{

}

void Game::event()
{

}

*/

void Game::shop()
{
    int i;
    cout << "TELL ME, WHAT CAN I DO FOR YOU?" << endl << endl;

    cout << "1: BUY QUENQUEN" << endl
         << "2: BUY SMARFON"  << endl
         << "3: BUY WEAPON"   << endl
         << "4: BUY ARMOR"    << endl
         << "5: SELL WEAPON"  << endl
         << "6: SELL ARMOR"   << endl
         << "0: EXIT"         << endl;
    cin >> i;
    while(i != 0)
    {
        cout << "1: BUY QUENQUEN" << endl
             << "2: BUY SMARFON"  << endl
             << "3: BUY WEAPON"   << endl
             << "4: BUY ARMOR"    << endl
             << "5: SELL WEAPON"  << endl
             << "6: SELL ARMOR"   << endl
             << "0: EXIT"         << endl;
        cin >> i;

        while(i < 0 || i > 6)
        {
            cout << "WHAT? SPEAK MY LENGUAGE!" << endl << endl
                << "1: BUY QUENQUEN" << endl
                << "2: BUY SMARFON"  << endl
                << "3: BUY WEAPON"   << endl
                << "4: BUY ARMOR"    << endl
                << "5: SELL WEAPON"  << endl
                << "6: SELL ARMOR"   << endl
                << "0: EXIT"         << endl;
            cin >> i;
        }

        switch(i)
        {
            case 0:
                break;
            case 1:
                character->buyQuenquen();
                break;
            case 2:
                character->buySmarfon();
                break;
            case 3:
                //character->buyWeapon(weaponStock());
                break;
            case 4:
                //character->buyArmor(armorStock());
                break;
            case 5:
                character->sellWeapon();
                break;
            case 6:
                character->sellArmor();
                break;
        }
    }
    cout << "SEE YA SOON..." << endl;
}


//REST

void Game::rest()
{
    this->character->heal(30);
    this->character->energyUp(5);
}


//LORE

/*void Game::lore()const
{

}*/





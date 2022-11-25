#include "Game.h"
#define T_0 time(NULL)

default_random_engine genGame(T_0);

Game::Game()
: _playing(true), _newGame(true), _character(NULL)
{}

//STATIC
float Game::normalF(float mid, float desv)
{
    normal_distribution<float> num(mid, desv);
    return num(genGame);
}


//COMMONS
void Game::play()
{
    int i;
    if(_newGame == true)
    {
        setCharacter();
        _newGame = false;
        return;
    }
    else if(_character->getLife() > 0)
    {
        i = menu();

        switch(i)
        {
        case 1:
                _character->travel();
                break;

        /*case 2:
                lore();
                break;*/
        case 3:
                _character->show();
                break;
        case 0:
                delete _character;
                _playing = false;
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

    ///NAME
    cout << "WELCOME! CHOOSE YOUR NAME"  << endl
         << "-------  ------ ---- ----"  << endl << endl;
    getline(cin, name);
    system("cls");

    ///SEX
    sex = sexSpeach();

    ///CLASS
    i = clasSpeach();

    switch(i)
    {
    case 1:
        _character = new Kaskam(name, sex);
        cout << "!!! KASKAM !!!" << "\n\n...";
        system("pause");
        break;
    case 2:
        _character = new Cristian(name, sex);
        cout << "Cristian, sir!!!" << "\n\n...";
        system("pause");
        break;
    case 3:
        _character = new Human(name, sex);
        cout << "! WITH ME OR AGAINST ME !" << "\n\n...";
        system("pause");
        break;
    }
}

char Game::sexSpeach()const
{
    char c;
    cout << "CHOOSE YOUR SEX (M/F)"  << endl
         << "------ ---- --- -----"  << endl << endl;
    cin >> c;
    c = toupper(c);

    while(c != 'M' && c != 'F')
    {
        system("cls");
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl;
        system("pause");
        cout << "CHOOSE YOUR SEX (M/F)"  << endl
             << "------ ---- --- -----"  << endl << endl;
        cin >> c;
        c = toupper(c);
    }
    system("cls");
    return c;
}

int Game::clasSpeach()const
{
    int i;
    cout << "CHOOSE YOUR CLASS" << endl
         << "------ ---- -----" << endl << endl
         << "1: Kaskam"     << endl
         << "2: Cristian"   << endl
         << "3: Human"      << endl;
    cin >> i;

    while(i < 1 || i > 3)
    {
        system("cls");
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl;
        system("pause");
        cout << "CHOOSE YOUR CLASS" << endl
             << "------ ---- -----" << endl << endl
             << "1: Kaskam"     << endl
             << "2: Cristian"   << endl
             << "3: Human"      << endl;
        cin >> i;
    }
    system("cls");
    return i;
}

int Game::menu()const
{
    int i;
    system("cls");
    cout << "MENU" << endl
         << "----"  << endl << endl
         << "1: TRAVEL" << endl
         << "2: LORE"   << endl
         << "3: STATS"  << endl
         << "0: EXIT"   << endl;
    cin >> i;

    while(i < 0 || i > 3)
    {
        system("cls");
        cout << "WRONG ANSWER, PLEASE RE-ENTER" << endl << endl;
        system("pause");
        cout << "MENU"  << endl
             << "----"  << endl << endl
             << "1: TRAVEL" << endl
             << "2: LORE"   << endl
             << "3: STATS"  << endl
             << "0: EXIT"   << endl;
        cin >> i;
    }
    system("cls");
    return i;
}

void Game::death()
{
    int i;
    delete _character;
    _character = NULL;

    cout << "GAME OVER!" << endl
         << "---- ----"  << endl << endl
         << "1: NEW GAME" << endl
         << "0: EXIT" << endl;
    cin >> i;

    while(i < 0 || i > 1)
    {
        system("cls");
        cout << "WRONG ANSWER, PLEASE RE-ENTER (1/0)" << endl;
        cin >> i;
    }
    system("cls");

    switch(i)
    {
    case 1:
            _newGame = true;
            break;
    case 0:
            _playing = false;
            break;
    }
}

/*void Game::lore()const
{

}*/



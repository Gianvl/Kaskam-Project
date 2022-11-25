#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const string& name, int life, float damage, float defense,
             int points, int gold)
:_name(name), _life(life), _lifeMax(life), _damage(damage), _defense(defense),
 _points(points), _gold(gold)
{}

float Enemy::attack()const
{
    return Game::normalF(_damage, _damage/3.3);
}

void Enemy::defend(float dmg)
{
    int realDmg = dmg - Game::normalF(_defense, 1.5);
    _life -= (realDmg > 0 ? realDmg : 0);
    cout << "DAMAGE TAKEN: " << realDmg << endl;
}

//KARKARAM

Karkaram::Karkaram()
:Enemy("Karkaram", 100, 8.0, 5.0, 3, 10)
{}

//PUNGA

Punga::Punga()
:Enemy("Punga", 60, 5.0, 3.0, 1, 5)
{}


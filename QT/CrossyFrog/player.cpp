#include "player.h"

Player::Player(string name,Resources *resources)
{
    itsName = name;
    new Frog(52,52,resources);
}

string Player::getItsName() const
{
    return itsName;
}

int Player::getItsScore() const
{
    return itsScore;
}

void Player::setItsScore(int value)
{
    itsScore = value;
}

Frog *Player::getItsFrog() const
{
    return itsFrog;
}

void Player::setItsFrog(Frog *value)
{
    itsFrog = value;
}

void Player::setItsName(const string &value)
{
    itsName = value;
}

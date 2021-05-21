#include "player.h"

Player::Player(string name)
{
    itsName = name;
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

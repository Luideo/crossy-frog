#include "player.h"

Player::Player(string name,Resources *resources)
{
    itsName = name;
    new Frog(52,52,resources,resources->getImages().at("frogM"));
}

string Player::getItsName() const
{
    return itsName;
}

int Player::getItsScore() const
{
    return itsMaxScore;
}

void Player::setItsScore(int value)
{
    itsMaxScore = value;
}

Frog *Player::getItsFrog() const
{
    return itsFrog;
}

void Player::setItsFrog(Frog *value)
{
    itsFrog = value;
}

int Player::getItsMaxScore() const
{
    return itsMaxScore;
}

void Player::goUp()
{
    if(itsScore==itsMaxScore){ //If the both scores are equal we can up the max score
        itsMaxScore++;
    }//Otherwise it mean that the frog have gone down so we have to retablish the normal score before the best score
    itsScore++;
}

void Player::goDown()
{
    itsScore--;
}

void Player::setItsName(const string &value)
{
    itsName = value;
}

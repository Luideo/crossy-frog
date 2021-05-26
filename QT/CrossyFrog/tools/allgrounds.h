#ifndef ALLGROUNDS_H
#define ALLGROUNDS_H

#include "tools/includes.h"
#include "tools/ground.h"

class AllGrounds
{
public:
    AllGrounds(Resources *resources);
    ///
    /// \brief randGround method that return a ground randomly
    /// \return Random ground
    ///
    Ground *randGround();
    ///
    /// \brief This method return the default ground (avoid water for the first for example)
    /// \return Default Ground
    ///
    Ground *defaultGround();

private:
    ///
    /// \brief vector of all the Ground present in the game
    ///
    vector<Ground*> allGround;
    ///
    /// \brief Value of the timer /10 in millis
    ///
    unsigned long int tickTimer=0;
    ///
    /// \brief allBlocks
    ///
    AllBlocks *allBlocks;

private slots:
    ///
    /// \brief this method is call by the timer every tick
    ///
    void tick();
};

#endif // ALLGROUNDS_H

#ifndef ALLGROUNDS_H
#define ALLGROUNDS_H

#include "tools/includes.h"
#include "tools/ground.h"

class AllGrounds
{
public:
    AllGrounds();
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
};

#endif // ALLGROUNDS_H

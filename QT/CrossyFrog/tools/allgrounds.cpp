#include "allgrounds.h"

AllGrounds::AllGrounds()
{
    //Create alls the ground
    Ground *g1 = new Ground("../CrossyFrog/res/ground/g1.txt");
    allGround.push_back(g1);
    Ground *g2 = new Ground("../CrossyFrog/res/ground/g2.txt");
    allGround.push_back(g2);
    Ground *g3 = new Ground("../CrossyFrog/res/ground/g3.txt");
    allGround.push_back(g3);
    Ground *g4 = new Ground("../CrossyFrog/res/ground/g4.txt");
    allGround.push_back(g4);
}

Ground *AllGrounds::randGround()
{
    //Return random ground in the vector of ground
    return allGround.at(rand()%allGround.size());
}

Ground *AllGrounds::defaultGround()
{
    //Return the default ground
    return allGround.at(0);
}

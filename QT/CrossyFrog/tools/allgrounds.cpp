#include "allgrounds.h"

AllGrounds::AllGrounds(Resources * resources)
{
    //Create a timer to now the time that take to load all the map
    QElapsedTimer *timer = new QElapsedTimer;
    timer->start();
    //Creation de tout les blocks
    allBlocks = new AllBlocks(resources);
    //Create alls the ground
    Ground *g1 = new Ground("../CrossyFrog/res/ground/g1.txt",allBlocks);
    allGround.push_back(g1);
    Ground *g2 = new Ground("../CrossyFrog/res/ground/g2.txt",allBlocks);
    allGround.push_back(g2);
    Ground *g3 = new Ground("../CrossyFrog/res/ground/g3.txt",allBlocks);
    allGround.push_back(g3);
    Ground *g4 = new Ground("../CrossyFrog/res/ground/g4.txt",allBlocks);
    allGround.push_back(g4);
    Ground *g5 = new Ground("../CrossyFrog/res/ground/g5.txt",allBlocks);
    allGround.push_back(g5);
    qDebug() << "Chargement des maps en : " << timer->elapsed() << "ms";
}

AllGrounds::AllGrounds()
{

}

Ground AllGrounds::randGround()
{
    //Return random ground in the vector of ground
    return *allGround.at(rand()%allGround.size());
}

Ground AllGrounds::defaultGround()
{
    //Return the default ground
    return *allGround.at(0);
}

void AllGrounds::tick()
{
    //Rajoute 1 au tick
    tickTimer++;
}

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
    Ground *g6 = new Ground("../CrossyFrog/res/ground/g6.txt",allBlocks);
    allGround.push_back(g6);
    Ground *g7 = new Ground("../CrossyFrog/res/ground/g7.txt",allBlocks);
    allGround.push_back(g7);
    Ground *g8 = new Ground("../CrossyFrog/res/ground/g8.txt",allBlocks);
    allGround.push_back(g8);
    Ground * g9 = new Ground("../CrossyFrog/res/ground/g9.txt",allBlocks);
    allGround.push_back(g9);
    Ground * g10 = new Ground("../CrossyFrog/res/ground/g10.txt",allBlocks);
    allGround.push_back(g10);
    Ground * g11 = new Ground("../CrossyFrog/res/ground/bush.txt",allBlocks);
    allGround.push_back(g11);
    Ground * g12 = new Ground("../CrossyFrog/res/ground/flaque.txt",allBlocks);
    allGround.push_back(g12);
    Ground * g13 = new Ground("../CrossyFrog/res/ground/flaqueR.txt",allBlocks);
    allGround.push_back(g13);
    Ground * g14 = new Ground("../CrossyFrog/res/ground/flaqueT.txt",allBlocks);
    allGround.push_back(g14);
    Ground * g15 = new Ground("../CrossyFrog/res/ground/flaqueW.txt",allBlocks);
    allGround.push_back(g15);
    Ground * g16 = new Ground("../CrossyFrog/res/ground/g11.txt",allBlocks);
    allGround.push_back(g16);
    Ground * g17 = new Ground("../CrossyFrog/res/ground/g12.txt",allBlocks);
    allGround.push_back(g17);
    Ground * g18 = new Ground("../CrossyFrog/res/ground/g13.txt",allBlocks);
    allGround.push_back(g18);
    Ground * g19 = new Ground("../CrossyFrog/res/ground/g13.txt",allBlocks);
    allGround.push_back(g19);
    Ground * g20 = new Ground("../CrossyFrog/res/ground/g14.txt",allBlocks);
    allGround.push_back(g20);
    Ground * g21 = new Ground("../CrossyFrog/res/ground/p41.txt",allBlocks);
    allGround.push_back(g21);
    Ground * g22 = new Ground("../CrossyFrog/res/ground/p42.txt",allBlocks);
    allGround.push_back(g22);
    Ground * g23 = new Ground("../CrossyFrog/res/ground/p43.txt",allBlocks);
    allGround.push_back(g23);
    Ground * g24 = new Ground("../CrossyFrog/res/ground/p44.txt",allBlocks);
    allGround.push_back(g24);
    Ground * g25 = new Ground("../CrossyFrog/res/ground/p45.txt",allBlocks);
    allGround.push_back(g25);
    Ground * g26 = new Ground("../CrossyFrog/res/ground/pattern (1).txt",allBlocks);
    allGround.push_back(g26);
    Ground * g27 = new Ground("../CrossyFrog/res/ground/pattern (2).txt",allBlocks);
    allGround.push_back(g27);
    Ground * g28 = new Ground("../CrossyFrog/res/ground/pattern (3).txt",allBlocks);
    allGround.push_back(g28);
    Ground * g29 = new Ground("../CrossyFrog/res/ground/pattern (4).txt",allBlocks);
    allGround.push_back(g29);
    Ground * g30 = new Ground("../CrossyFrog/res/ground/pattern (5).txt",allBlocks);
    allGround.push_back(g30);
    Ground * g31 = new Ground("../CrossyFrog/res/ground/pattern (6).txt",allBlocks);
    allGround.push_back(g31);
    Ground * g32 = new Ground("../CrossyFrog/res/ground/p46.txt",allBlocks);
    allGround.push_back(g32);

    //Put here new patterns to add
    /*Ground *gn= new Ground("../CrossyFrog/res/ground/gn.txt",allBlocks);
    allGround.push_back(gn);*/

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

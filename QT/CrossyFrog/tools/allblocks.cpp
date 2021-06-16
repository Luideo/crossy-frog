#include "allblocks.h"

AllBlocks::AllBlocks(Resources *resources)
{
    //Set the resources
    this->resources = resources;
    qDebug() << "Creation des blocks";

    //Create the blocks
    dirt.push_back(new Block("dirt1",true,resources));
    dirt.push_back(new Block("dirt2",true,resources));
    grass.push_back(new Block("grass1",true,resources));
    grass.push_back(new Block("grass2",true,resources));
    grass.push_back(new Block("grass3",true,resources));
    grass.push_back(new Block("grass4",true,resources));
    grass.push_back(new Block("grass5",true,resources));
    water.push_back(new Block("water1",false,resources));
    water.push_back(new Block("water2",false,resources));
    water.push_back(new Block("water3",false,resources));
    road = new Block("road",true,resources);
    rail = new Block("rail",true,resources);
    bush = new Block("bush",false,resources);
}

Block *AllBlocks::getDirt() const
{
    Block * dirtBlock = dirt.at(rand()%(dirt.size()));
    dirtBlock->setBackground(dirtBlock->getBackground().transformed(QMatrix().rotate((rand()%4)*90)));
    return dirtBlock;
}

Block *AllBlocks::getGrass() const
{
    Block * grassBlock = grass.at(rand()%(grass.size()));
    grassBlock->setBackground(grassBlock->getBackground().transformed(QMatrix().rotate((rand()%4)*90)));
    return grassBlock;
}

Block *AllBlocks::getWater() const
{
    return water.at(rand()%(water.size()));
}

Block *AllBlocks::getRoad() const
{
    return road;
}

Block *AllBlocks::getRail() const
{
    return rail;
}

Block *AllBlocks::getBush() const
{
    Block * bushBlock = bush;
    bushBlock->setBackground(bushBlock->getBackground().transformed(QMatrix().rotate((rand()%4)*90)));
    return bushBlock;
}

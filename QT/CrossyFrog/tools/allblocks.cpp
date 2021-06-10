#include "allblocks.h"

AllBlocks::AllBlocks(Resources *resources)
{
    //Set the resources
    this->resources = resources;
    qDebug() << "Creation des blocks";
    //Create the blocks
    dirt = new Block("dirt",true,resources);
    grass.push_back(new Block("grass1",true,resources));
    grass.push_back(new Block("grass2",true,resources));
    grass.push_back(new Block("grass3",true,resources));
    grass.push_back(new Block("grass4",true,resources));
    water = new Block("water",false,resources);
    road = new Block("road",true,resources);
}

Block *AllBlocks::getDirt() const
{
    return dirt;
}

Block *AllBlocks::getGrass() const
{
    return grass.at(rand()%(grass.size()-1));
}

Block *AllBlocks::getWater() const
{
    return water;
}

Block *AllBlocks::getRoad() const
{
    return road;
}

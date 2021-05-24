#include "allblocks.h"

AllBlocks::AllBlocks()
{
}

Block AllBlocks::dirt(){
    return Block("../CrossyFrog/res/blocks/dirt",true,"dirt");
}

Block AllBlocks::grass(){
    return Block("../CrossyFrog/res/blocks/grass",true,"grass");
}

Block AllBlocks::water(){
    return Block("../CrossyFrog/res/blocks/water",false,"water");
}

#ifndef ALLBLOCKS_H
#define ALLBLOCKS_H

#include "tools/includes.h"
#include "tools/block.h"

class AllBlocks
{
public:
    AllBlocks();

    //Create all the blocks present in the game
    ///
    /// \brief dirt
    /// \return
    ///
    static Block dirt();
    ///
    /// \brief grass
    /// \return
    ///
    static Block grass();
    ///
    /// \brief water
    /// \return
    ///
    static Block water();
};

#endif // ALLBLOCKS_H

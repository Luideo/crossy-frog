#ifndef ALLBLOCKS_H
#define ALLBLOCKS_H

#include "tools/includes.h"
#include "tools/block.h"

class AllBlocks
{
public:
    AllBlocks(Resources * resources);

    ///
    /// \brief getDirt
    /// \return
    ///
    Block *getDirt() const;
    ///
    /// \brief getGrass
    /// \return
    ///
    Block *getGrass() const;
    ///
    /// \brief getWater
    /// \return
    ///
    Block *getWater() const;

private:
    ///
    /// \brief all the resources we need
    ///
    Resources *resources;
    //Create all the blocks present in the game
    ///
    /// \brief dirt
    /// \return
    ///
    Block *dirt;
    ///
    /// \brief grass
    /// \return
    ///
    Block *grass;
    ///
    /// \brief water
    /// \return
    ///
    Block*water;
};

#endif // ALLBLOCKS_H

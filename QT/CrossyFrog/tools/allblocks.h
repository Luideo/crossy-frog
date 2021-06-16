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
    ///
    /// \brief getRoad
    /// \return
    ///
    Block *getRoad() const;
    ///
    /// \brief getRail
    /// \return
    ///
    Block *getRail() const;
    ///
    /// \brief getBush
    /// \return
    ///
    Block *getBush() const;

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
    vector<Block *> dirt;
    ///
    /// \brief grass
    /// \return
    ///
    vector<Block *> grass;
    ///
    /// \brief water
    /// \return
    ///
    vector<Block *> water;
    ///
    /// \brief road
    ///
    Block *road;
    ///
    /// \brief rail
    ///
    Block *rail;
    ///
    /// \brief bush
    ///
    Block *bush;
};

#endif // ALLBLOCKS_H

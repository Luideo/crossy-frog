#ifndef GROUND_H
#define GROUND_H

#include "tools/includes.h"
#include "tools/allblocks.h"

class Ground
{
public:
    Ground(string path);

    ///
    /// \brief Get the blocks
    /// \return vector<Block>
    ///
    vector<vector<Block*>> getBlocks() const;
    ///
    /// \brief Get the blocks
    /// \param vector<Block>
    ///
    void setBlocks(const vector<vector<Block*>> &value);
    ///
    /// \brief stringToBlock
    /// \param vec
    /// \return
    ///
    vector<Block *> stringToBlock(vector<string> vec);

private:
    ///
    /// \brief All the blocks in the ground
    ///
    vector<vector<Block*>> blocks;
};

#endif // GROUND_H

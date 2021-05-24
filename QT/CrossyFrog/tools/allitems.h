#ifndef ALLITEMS_H
#define ALLITEMS_H

#include "tools/includes.h"
#include "tools/item.h"

class AllItems
{
public:
    AllItems();

private:
    ///
    /// \brief All the item present in the game
    ///
    vector<Item> allItems;
};

#endif // ALLITEMS_H

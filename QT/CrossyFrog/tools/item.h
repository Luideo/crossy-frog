#ifndef ITEM_H
#define ITEM_H

#include "tools/includes.h"

class Item
{
public:
    Item();

private:
    ///
    /// \brief posX of the patern
    ///
    int posX;
    ///
    /// \brief posY of the patern
    ///
    int posY;
    ///
    /// \brief width of the patern
    ///
    int width;
    ///
    /// \brief height of the patern
    ///
    int height;
    ///
    /// \brief The image of the item
    ///
    QImage item;
    ///
    /// \brief If the item is crossable
    ///
    bool crossable;
};

#endif // ITEM_H

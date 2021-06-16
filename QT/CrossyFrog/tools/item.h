#ifndef ITEM_H
#define ITEM_H

#include "tools/includes.h"
#include "resources.h"
#include "frog.h"

class Item
{
public:
    Item(int posx,int posy,QImage background,string name,bool crossable,int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP,Resources *resources);
    ///
    /// \brief getItsSpeedX
    /// \return
    ///
    int getItsSpeedX() const;
    ///
    /// \brief setItsSpeedX
    /// \param value
    ///
    void setItsSpeedX(int value);
    ///
    /// \brief getItsSpeedY
    /// \return
    ///
    int getItsSpeedY() const;
    ///
    /// \brief setItsSpeedY
    /// \param value
    ///
    void setItsSpeedY(int value);
    ///
    /// \brief getItsPosx
    /// \return
    ///
    int getItsPosx() const;
    ///
    /// \brief getItsPosy
    /// \return
    ///
    int getItsPosy() const;
    ///
    /// \brief getItsBackground
    /// \return
    ///
    QImage getItsBackground() const;
    ///
    /// \brief moveFrame is a method that move the current item for a frame
    ///
    void moveFrame();
    ///
    /// \brief getItsCrossability
    /// \return
    ///
    bool getItsCrossability() const;

private:
    ///
    /// \brief posx of the current item
    ///
    int itsPosx;
    ///
    /// \brief posy of the current item
    ///
    int itsPosy;
    ///
    /// \brief speedX of the current item
    ///
    int itsSpeedX=0;
    ///
    /// \brief speedY of the current item
    ///
    int itsSpeedY=0;
    ///
    /// \brief background of the current item
    ///
    QImage itsBackground;
    ///
    /// \brief name of the item
    ///
    string itsName;
    ///
    /// \brief itsCrossability
    ///
    bool itsCrossability;
    ///
    /// \brief Offset of the playground(middle screen) X
    ///
    int OFFSETX = 158;
    ///
    /// \brief Offset of the playground(middle screen) Y
    ///
    int OFFSETY = 36;
    ///
    /// \brief Width of the playgorund
    ///
    int WIDTHP = 884;
    ///
    /// \brief Width of the playgorund
    ///
    int HEIGHTP = 728;
    ///
    /// \brief resources
    ///
    Resources *resources;
};

#endif // ITEM_H

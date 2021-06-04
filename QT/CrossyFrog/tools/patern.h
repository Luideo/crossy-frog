#ifndef PATERN_H
#define PATERN_H

#include "tools/includes.h"
#include "tools/allgrounds.h"
#include "tools/item.h"
#include "resources.h"

class Patern
{
public:
    Patern(int posX,int posY,int width,int height,int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP,int sizeCase,AllGrounds atg,string name,Resources *resources);

    ///
    /// \brief generate a random ground
    ///
    void randGround();
    ///
    /// \brief generate the default ground (dirt)
    ///
    void defaultGround();
    ///
    /// \brief mehtod to draw all the blocks
    /// \param itsPainter
    ///
    void draw(QPainter *itsPainter);
    ///
    /// \brief method to draw the grid on the patern
    /// \param itsPainter
    ///
    void drawGrid(QPainter *itsPainter);
    ///
    /// \brief Get the position Y of this patern
    /// \return the position Y (int)
    ///
    int getPosY() const;
    ///
    /// \brief Set the position Y of this patern
    /// \param the position Y (int)
    ///
    void setPosY(int value);
    ///
    /// \brief moveBottom method call each tick, replace top if necessary
    /// \param The speed in px
    ///
    void moveBottom(int speed);
    ///
    /// \brief Get the ground of this patern
    /// \return the ground
    ///
    Ground *getGround() const;
    ///
    /// \brief getName
    /// \return
    ///
    string getName() const;
    ///
    /// \brief the resources of the game
    ///
    Resources *resources;
    ///
    /// \brief getAllItems
    /// \return
    ///
    vector<Item *> getAllItems() const;

private:
    ///
    /// \brief A ground its a composition of blocks where the frog will run (not a pointer cause of collision problems)
    ///
    Ground *ground;
    ///
    /// \brief Class of all the ground present in the game
    ///
    AllGrounds alls;
    ///
    /// \brief allItems on the current patern
    ///
    vector<Item*> allItems;
    ///
    /// \brief posX of the patern (ATTENTION! DOSENT PUT OFFSET)
    ///
    int posX;
    ///
    /// \brief posY of the patern (ATTENTION! DOSENT PUT OFFSET)
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
    /// \brief The size of a case on the playground
    ///
    int sizeCase;
    ///
    /// \brief name of the patern
    ///
    string name;
    ///
    /// \brief setItems method that set all the items needed on the map
    ///
    void setItems();
};

#endif // PATERN_H

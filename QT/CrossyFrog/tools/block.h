#ifndef BLOCK_H
#define BLOCK_H

#include "tools/includes.h"

class Resources;

class Block
{
public:
    Block(string imageName,bool crossabilty,Resources * resources);

    ///
    /// \brief Get the Background
    /// \return the image of the background
    ///
    QImage getBackground() const;
    ///
    /// \brief Set the Background
    /// \param the image of the background
    ///
    void setBackground(const QImage &value);
    ///
    /// \brief Get the crossability
    /// \return the bool if it's crossable or not
    ///
    bool getCrossable() const;
    ///
    /// \brief Set the crossability
    /// \param the bool if it's crossable or not
    ///
    void setCrossable(bool value);
    ///
    /// \brief getPosX
    /// \return
    ///
    int getPosX() const;
    ///
    /// \brief setPosX
    /// \param value
    ///
    void setPosX(int value);
    ///
    /// \brief getPosY
    /// \return
    ///
    int getPosY() const;
    ///
    /// \brief setPosY
    /// \param value
    ///
    void setPosY(int value);
    ///
    /// \brief getName
    /// \return
    ///
    string getName() const;
    ///
    /// \brief setName
    /// \param value
    ///
    void setName(const string &value);

private:
    ///
    /// \brief Image of the block
    ///
    QImage background;
    ///
    /// \brief If the ground is crossable
    ///
    bool crossable;
    ///
    /// \brief The name of the block (dirt/water/...)
    ///
    string name;
    ///
    /// \brief posX update every paint event
    ///
    int posX=0;
    ///
    /// \brief posY update every paint event
    ///
    int posY=0;
    ///
    /// \brief all the resources we need
    ///
    Resources *resources;
};

#endif // BLOCK_H

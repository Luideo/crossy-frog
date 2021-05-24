#ifndef FROG_H
#define FROG_H

#include "tools/includes.h"

class Frog
{
public:
    Frog(int width,int height);

    ///
    /// \brief Get the shape of the frog (its an Image)
    /// \return Image of the frog
    ///
    QImage getShape() const;
    ///
    /// \brief Set the shape of the frog (its an Image)
    /// \param Image of the frog
    ///
    void setShape(const QImage &value);
    ///
    /// \brief Get the shape of the frog (its an Image)
    /// \return Image of the frog
    ///
    QImage getOriginalShape() const;
    ///
    /// \brief Get the pos X of the frog
    /// \return the X pos (int)
    ///
    int getPosX() const;
    ///
    /// \brief Set the pos X of the frog
    /// \param X pos
    ///
    void setPosX(int value);
    ///
    /// \brief  Get the pos Y of the frog
    /// \return the Y pos (int)
    ///
    int getPosY() const;
    ///
    /// \brief Set the pos Y of the frog
    /// \param Y pos
    ///
    void setPosY(int value);
    ///
    /// \brief Get the Width of the frog
    /// \return the Width (int)
    ///
    int getWidth() const;
    ///
    /// \brief Set the Width of the frog
    /// \param the Width (int)
    ///
    void setWidth(int value);
    ///
    /// \brief  Get the Height of the frog
    /// \return the Height (int)
    ///
    int getHeight() const;
    ///
    /// \brief Set the Height of the frog
    /// \return the Height (int)
    ///
    void setHeight(int value);
    ///
    /// \brief  Get the Rotation of the frog
    /// \return The rotation (int between 0-360)
    ///
    int getRotation() const;
    ///
    /// \brief Set the Rotation of the frog
    /// \param The rotation (int between 0-360)
    ///
    void setRotation(int value);
    ///
    /// \brief moveBottom method that move the frog 1px bott, called every tick
    /// \param The speed in px
    ///
    void moveBottom(int speed);

private:
    ///
    /// \brief The image according to the shape of the frog
    ///
    QImage shape;
    ///
    /// \brief The image according to the shape of the frog (only uses is for the rotation reset)
    ///
    QImage originalShape;
    ///
    /// \brief The X position of the frog
    ///
    int posX;
    ///
    /// \brief The Y position of the frog
    ///
    int posY;
    ///
    /// \brief The Width of the frog
    ///
    int width;
    ///
    /// \brief The Height of the frog
    ///
    int height;
    ///
    /// \brief The current rotation of the frog, start at 0
    ///
    int rotation=0;
};

#endif // FROG_H

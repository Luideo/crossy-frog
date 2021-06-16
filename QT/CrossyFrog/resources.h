#ifndef RESOURCES_H
#define RESOURCES_H

#include "tools/includes.h"

class Resources
{
public:
    Resources(QTranslator *translator);

    ///
    /// \brief getImages
    /// \return the map of images
    ///
    map<string, QImage> getImages();
    ///
    /// \brief setImages
    /// \param the map of images
    ///
    void setImages(const map<string, QImage> &value);
    ///
    /// \brief draw the loading bar
    /// \param itsPainter
    ///
    void draw(QPainter *itsPainter,QRect progress);
    ///
    /// \brief getTranslator
    /// \return
    ///
    QTranslator *getTranslator() const;
    ///
    /// \brief getLanguage
    /// \return
    ///
    string getLanguage() const;
    ///
    /// \brief setLanguage
    /// \param value
    ///
    void setLanguage(const string &value);
    ///
    /// \brief loadSettings method
    ///
    void loadSettings();

private:
    ///
    /// \brief blocksBaground is the map that contain all the background of all blocks and the frog ... etc etc
    ///
    map<string,QImage> images;
    ///
    /// \brief index is the num of the item that is loaded
    ///
    int index;
    ///
    /// \brief the total is the total of element to load
    ///
    int total=4;
    ///
    /// \brief progress bar (not a pointer because we don't want to change the initial value)
    ///
    QRect progress;
    ///
    /// \brief The translator of the game
    ///
    QTranslator *translator;
    ///
    /// \brief the language selected
    ///
    string language="../CrossyFrog/settings.txt";
};

#endif // RESOURCES_H

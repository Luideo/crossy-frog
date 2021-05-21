#ifndef TOOLS_H
#define TOOLS_H

#include <QColor>

class Tools{
public:
    //Creation des couleurs
    static QColor COLOR_BLACK(){ return QColor(0,0,0,255); };
    static QColor COLOR_WHITE(){ return QColor(255,255,255,255); };
    static QColor COLOR_NIGHT(){ return QColor(11,5,92,255); };
    static QColor COLOR_GRASS(){ return QColor(20,147,39,255); };
    static QColor COLOR_CYANSKY(){ return QColor(100,153,255,255); };
};

#endif // TOOLS_H

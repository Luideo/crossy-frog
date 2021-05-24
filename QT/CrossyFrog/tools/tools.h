#ifndef TOOLS_H
#define TOOLS_H

#include <QColor>

using namespace std;

class Tools{
public:
    //Creation des couleurs
    static QColor COLOR_BLACK(){ return QColor(0,0,0,255); };
    static QColor COLOR_WHITE(){ return QColor(255,255,255,255); };
    static QColor COLOR_NIGHT(){ return QColor(11,5,92,255); };
    static QColor COLOR_GRASS(){ return QColor(20,147,39,255); };
    static QColor COLOR_CYANSKY(){ return QColor(100,153,255,255); };
    static QColor COLOR_RED(){ return QColor(255,0,0,255); };
    static QColor COLOR_GREEN(){ return QColor(0,255,0,255); }
    ///
    /// \brief method to split a text with a separator
    /// \param s
    /// \param separator
    /// \return
    ///
    static vector<string> split(string s,char separator)
    {
        vector<string> finalVector;
        string temp;
        for(char c : s){
            if(c != separator){
                temp+=c;
            }else{
                finalVector.push_back(temp);
                temp="";
            }
        }
        finalVector.push_back(temp);
        return finalVector;
    }
};

#endif // TOOLS_H

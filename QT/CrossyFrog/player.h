#ifndef PLAYER_H
#define PLAYER_H
#include "tools/includes.h"
#include "frog.h"


class Player
{
public:
    Player(string name);

    ///
    /// \brief Get the name of the player
    /// \return Name of the player
    ///
    string getItsName() const;
    ///
    /// \brief Set the name of the player
    /// \value Name of the player
    ///
    void setItsName(const string &value);
    ///
    /// \brief Get the score of the player
    /// \return Score format int
    ///
    int getItsScore() const;
    ///
    /// \brief Set the score of the player
    /// \param Score
    ///
    void setItsScore(int value);
    ///
    /// \brief Get the frog of the player
    /// \return The frog format class *Frog
    ///
    Frog *getItsFrog() const;
    ///
    /// \brief Set the frog of the player
    /// \param *Frog
    ///
    void setItsFrog(Frog *value);

private:
    ///
    /// \brief Name of the current player
    ///
    string itsName;
    ///
    /// \brief The frog of the player
    ///
    Frog *itsFrog = new Frog(52,52);
    ///
    /// \brief The score of the player
    ///
    int itsScore=0;
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H
#include "tools/includes.h"
#include "frog.h"


class Player
{
public:
    Player(string name,Resources *resources);

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
    ///
    /// \brief getItsMaxScore
    /// \return
    ///
    int getItsMaxScore() const;
    ///
    /// \brief goUp method called when the frog go up
    ///
    void goUp();
    ///
    /// \brief goDown method called when the frog go down
    ///
    void goDown();

private:
    ///
    /// \brief Name of the current player
    ///
    string itsName;
    ///
    /// \brief The frog of the player
    ///
    Frog *itsFrog;
    ///
    /// \brief The score of the player
    ///
    int itsMaxScore=0;
    ///
    /// \brief itsScore official (go down 1 do -1 on the score)
    ///
    int itsScore=0;
};

#endif // PLAYER_H

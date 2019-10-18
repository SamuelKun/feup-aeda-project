#pragma once

#include <iostream>
#include <Date.h>

using namespace std;

enum TypeGame {
    FriendMatch,
    EuropeCup,
    WorldCup,
    Cup
};

class Convocatoria {
    private:
        TypeGame typeGame;
        int numberGames;
        Date start;
        Date finish;
    public:
        Convocatoria(TypeGame typeGame, int numberGames, Date start, Date finish);
        TypeGame getTypeGame() const;
        int getNumberGames() const;
        Date getStart() const;
        Date getFinish() const;
        void setTypeGame(TypeGame typeGame);
        void setNumberGames(int numberGames);
        void setStart(Date start);
        void setFinish(Date finish);
};
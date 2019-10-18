#include <iostream>

#include <Convocatoria.h>

using namespace std;

Convocatoria::Convocatoria(TypeGame typeGame, int numberGames, Date start, Date finish) {
    this -> typeGame = typeGame;
    this -> numberGames = numberGames;
    this -> start = start;
    this -> finish = finish;
}

TypeGame Convocatoria::getTypeGame() const {
    return typeGame;
}

int Convocatoria::getNumberGames() const {
    return numberGames;
}

Date Convocatoria::getStart() const {
    return start;
}

Date Convocatoria::getFinish() const {
    return finish;
}

void Convocatoria::setTypeGame(TypeGame typeGame) {
    this -> typeGame = typeGame;
}

void Convocatoria::setNumberGames(int numberGames) {
    this -> numberGames = numberGames;
}

void Convocatoria::setStart(Date start) {
    this -> start = start;
}

void Convocatoria::setFinish(Date finish) {
    this -> finish = finish;
}
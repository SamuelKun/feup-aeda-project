//
// Created by diogo on 22/12/2019.
//

#ifndef COACH_H
#define COACH_H

#include <string>
#include "bst.h"

class Coach{
private:
    double numTitles;
    std::string name;
public:
    Coach() {}
    Coach(std::string name, double titles);
    void show() const;
    void setName(string n);
    std::string getName() const;
    double getTitles() const;
    void setTitles(double n);
    bool operator < (const Coach &c1) const;
    bool operator == (const Coach &c1) const;

};

class CoachTree
{
private:
    BST<Coach> tree;
public:

    CoachTree(): tree(Coach("",-1)) {};
    void addCoach(Coach &c);

    vector<Coach> searchName(std::string name);
    vector<Coach> searchTitle(double num);

    void updateCoachName(Coach c, std::string name);
    void updateCoachTitle(Coach c, double titles);
    void removeCoach(Coach c);
    void imprime() const;

    /*
    BST<PalavraSignificado> getPalavras() const;
    void lerDicionario(ifstream &fich);
    string consulta(string palavra) const;
    bool corrige(string palavra, string significado);
    void imprime() const;
     */
};



#endif


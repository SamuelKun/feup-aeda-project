#ifndef COACH_H
#define COACH_H

#include <string>
#include <vector>
#include <tuple>

#include "bst.h"
#include "Date.h"
#include "Person.h"

class Coach: public Person{
private:
    double numTitles;
    vector<std::tuple<string, Date, Date>> trainedTeams;
public:
    Coach() {}
    Coach(std::string name, Date birth, double titles);
    void show() const;
    void addTrainedTeam(string name, Date start, Date end);
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

    CoachTree(): tree(Coach("", Date(), -1)) {}; //Ver isto melhor depois
    void addCoach(Coach &c);

    vector<Coach> searchName(std::string name);
    vector<Coach> searchTitle(double num);

    void updateCoachName(Coach c, std::string name);
    void updateCoachTitle(Coach c, double titles);
    void removeCoach(Coach c);
    void imprime() const;
};



#endif


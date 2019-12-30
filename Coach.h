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
    bool currentCoach;
    vector<std::tuple<string, Date, Date>> trainedTeams;
public:
    Coach() {}
    Coach(std::string name, Date birth, bool current, double titles);
    void show() const;
    void addTrainedTeam(string name, Date start, Date end);
    void setCurrentCoach(bool c);
    double getTitles() const;
    bool getCurrentCoach() const;
    vector<std::tuple<string, Date, Date>> getTrainedTeams() const;
    void setTitles(double n);
    bool operator < (const Coach &c1) const;
    bool operator == (const Coach &c1) const;

};

class InvalidNumberTitles {
private:
    double numTitles;
public:
    InvalidNumberTitles (double num): numTitles(num) {}
    double getNumTitles() const {
        return numTitles;
    }
};

class NoCoach {
public:
    NoCoach() {}
    void show() const {
        cout << "This team dont have a main coach! " << endl;
    }
};


class CoachTree
{
private:
    BST<Coach> tree;
public:
    CoachTree(): tree(Coach("", Date(), false,-1)) {}; //Ver isto melhor depois
    void addCoach(Coach &c);
    BST<Coach> getTree();
    vector<Coach> searchName(std::string name);
    vector<Coach> searchTitle(double num);
    Coach searchCurrentCoach();
    void updateCoachName(Coach c, std::string name);
    void updateCoachTitle(Coach c, double titles);
    void removeCoach(Coach c);
    void imprime() const;
};






#endif


//
// Created by diogo on 22/12/2019.
//

#include "Coach.h"
#include "iostream"
#include <fstream>
#include <sstream>

Coach::Coach(std::string name, Date birth, bool current, double titles): Person(name, birth), currentCoach(current), numTitles(titles) {

}

void Coach::show() const {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Titles: " << numTitles << std::endl;
    std::cout << "Trained Teams: "<< endl;
    for(auto &i : trainedTeams){
        cout << " TeamName: " << get<0>(i)<< endl;
        cout << " Start: " << get<1>(i)<< endl;
        cout << " End: " << get<2>(i) << endl << endl;
    }
    cout << endl;
}

bool Coach::operator<(const Coach &c1) const {
    if(numTitles != c1.numTitles)
        return numTitles < c1.numTitles;
    else
        return getName() < c1.getName();
}

bool Coach::operator==(const Coach &c1) const {
    return getName() == c1.getName();
}


void Coach::setTitles(double titles) {
    this->numTitles = titles;
}

double Coach::getTitles() const {
    return numTitles;
}

void Coach::addTrainedTeam(string name, Date start, Date end) {
    std::tuple<string, Date, Date> newTeam = std::make_tuple(name, start, end);
    trainedTeams.push_back(newTeam);
}

bool Coach::getCurrentCoach() const {
    return currentCoach;
}

void Coach::setCurrentCoach(bool c) {
    this->currentCoach = c;
}

void CoachTree::imprime() const {
    int index = 0;
    BSTItrIn<Coach> it(tree);
    while (!it.isAtEnd()) {
        cout << "Index: " << index << endl;
        it.retrieve().show();
        it.advance();
        index++;
    }
}

void CoachTree::addCoach(Coach &c) {
    tree.insert(c);
}

vector<Coach> CoachTree::searchName(string name) {
    vector<Coach> c1;
    BSTItrIn<Coach> it(tree);

    while (!it.isAtEnd()) {
        if(it.retrieve().getName().find(name) != string::npos) {
            c1.push_back(it.retrieve());
        }
        it.advance();
    }
    if(c1.empty()) throw PersonNotFound(name);
    else return c1;
}


vector<Coach> CoachTree::searchTitle(double num) {
    vector<Coach> c1;
    BSTItrIn<Coach> it(tree);

    while (!it.isAtEnd()) {
        if(it.retrieve().getTitles() == num) {
            c1.push_back(it.retrieve());
        }
        it.advance();
    }
    if(c1.empty()) throw InvalidNumberTitles(num);
    else return c1;
}

void CoachTree::removeCoach(Coach c) {
    tree.remove(c);
}

void CoachTree::updateCoachName(Coach c, std::string name) {
    tree.remove(c);
    c.setName(name);
    tree.insert(c);
}

void CoachTree::updateCoachTitle(Coach c, double titles){
    tree.remove(c);
    c.setTitles(titles);
    tree.insert(c);
}

Coach CoachTree::searchCurrentCoach() {
    BSTItrIn<Coach> it(tree);

    while (!it.isAtEnd()) {
        if(it.retrieve().getCurrentCoach()) {
            return it.retrieve();
        }
        it.advance();
    }
    throw NoCoach();
}


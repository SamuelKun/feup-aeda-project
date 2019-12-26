//
// Created by diogo on 22/12/2019.
//

#include "Coach.h"
#include "iostream"
#include <fstream>
#include <sstream>

Coach::Coach(std::string name, double titles): name(name), numTitles(titles) {

}

void Coach::show() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Titles: " << numTitles << std::endl;
}

bool Coach::operator<(const Coach &c1) const {
    if(numTitles != c1.numTitles)
        return numTitles < c1.numTitles;
    else
        return name < c1.name;
}

bool Coach::operator==(const Coach &c1) const {
    return name == c1.name;
}

void Coach::setName(string name) {
    this->name = name;
}

void Coach::setTitles(double titles) {
    this->numTitles = titles;
}

std::string Coach::getName() const {
    return name;
}

double Coach::getTitles() const {
    return numTitles;
}

void CoachTree::imprime() const {
    BSTItrIn<Coach> it(tree);
    while (!it.isAtEnd()) {
        it.retrieve().show();
        it.advance();
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
    return c1;
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
    return c1;
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


#include <string>
#include <iomanip>
#include "Player.h"
#include "Date.h"

using namespace std;

Player::Player() {
}


Player::Player(string name, Date birth, string club, string position, int weight, int height, int value, double earnings): Person(name, birth), club(club), position(position),
                                                                                                                        weight(weight), height(height), value(value),
                                                                                                                        earnings(earnings) {
    this->insurance = value * 0.005;
}

string Player::getClub() const {
    return club;
}

string Player::getPosition() const {
    return position;
}

int Player::getWeight() const {
    return weight;
}

int Player::getHeight() const {
    return height;
}

int Player::getValue() const {
    return value;
}

double Player::getEarnings() const {
    return earnings;
}

double Player::getInsurance() const {
    return insurance;
}

void Player::setClub(string club) {
    this -> club = club;
}

void Player::setWeight(int weight) {
    this -> weight = weight;
}

void Player::setHeight(int height) {
    this -> height = height;
}

void Player::setValue(int value) {
    this -> value = value;
}

void Player::setEarnings(double value) {
    this -> earnings += value;
}

void Player::setPosition(string pos) {
    this->position = pos;
}


void Player::infoTable() const
{
    Person::infoTable();
    cout << setw(12) << getClub() << " | " << setw(10) << getPosition() << " | " << setw(6) << getWeight() << " | "
    << setw(8) << getHeight() << " | " << setw(7) << getValue() << " | " << setw(9) <<  getEarnings() << " |" << endl;
}

void Player::info() const {
    Person::info();
    cout << "Club: " << getClub() << endl;
    cout << "Position: " << getPosition() << endl;
    cout << "Weight: " << getWeight() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Value: " << getValue() << endl;
    cout << "Total Earnings: " << getEarnings() << endl;
}



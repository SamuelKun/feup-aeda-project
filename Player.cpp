#include <string>
#include <utility>
#include "Player.h"
#include "Date.h"

using namespace std;

Player::Player(string name, Date birth, string club, int weight, int height, int value, int insurance): Person(name, birth), club(club), weight(weight),
                                                                                                        height(height), value(value), insurance(insurance) {}

string Player::getClub() const {
    return club;
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

int Player::getInsurance() const {
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

void Player::setInsurance(int insurance) {
    this -> insurance = insurance;
}

void Player::info() const
{
    Person::info();
    cout << "Club: " << getClub() << endl;
    cout << "Weight: " << getWeight() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Value: " << getValue() << endl;
    cout << "Insurance: " << getInsurance() << endl;
}

/*
bool Player::operator<(const Player &p) {
    return this->getName() < p.getName();
}

ostream &operator<<(ostream &os, const Player &p) {
    vector<string>::const_iterator it;

    os << "All player data: " << endl << endl;
    os << "Name: " << p.getName() << endl;
    os << "Birthday: " << p.getBirthday() << endl;
    os << "Club: " << p.getClub() << endl;
    os << "Weight: " << p.getWeight() << endl;
    os << "Height: " << p.getHeight() << endl;
    os << "Value: " << p.getValue() << endl;
    os << "Insurance: " << p.getInsurance() << endl;
    return os;
}
*/


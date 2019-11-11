#include <string>
#include <iomanip>
#include "Player.h"
#include "Date.h"

using namespace std;

Player::Player() {
}


/// \brief Player constructor with the following« data
/// \param name Player's name
/// \param birth Player's birthday
/// \param club Player's club
/// \param weight Player's weight
/// \param height Player's height
/// \param value Player's value
/// \param insurance Player's insurance
Player::Player(string name, Date birth, string club, string position, int weight, int height, int value, double earnings): Person(name, birth), club(club), position(position),
                                                                                                                        weight(weight), height(height), value(value),
                                                                                                                        earnings(earnings) {
    this->insurance = value * 0.005;
}
/// \brief Get Method
/// \return Player's club
string Player::getClub() const {
    return club;
}
/// \brief Get Method
/// \return Player's position
string Player::getPosition() const {
    return position;
}
/// \brief Get Method
/// \return Player's weight
int Player::getWeight() const {
    return weight;
}
/// \brief Get Method
/// \return Player's height
int Player::getHeight() const {
    return height;
}
/// \brief Get Method
/// \return Player's Value
int Player::getValue() const {
    return value;
}
/// \brief Get Method
/// \return Player's insurance
double Player::getEarnings() const {
    return earnings;
}

double Player::getInsurance() const {
    return insurance;
}

/// \brief Set Method
/// \param club Player's club
void Player::setClub(string club) {
    this -> club = club;
}
/// \brief Set Method
/// \param weight Player's weight
void Player::setWeight(int weight) {
    this -> weight = weight;
}
/// \brief Set Method
/// \param height Player's height
void Player::setHeight(int height) {
    this -> height = height;
}
/// \brief Set Method
/// \param value Player's value
void Player::setValue(int value) {
    this -> value = value;
}
/// \brief Set Method
/// \param insurance Player's insurance
void Player::setEarnings(double value) {
    this -> earnings += value;
}

void Player::setPosition(string pos) {
    this->position = pos;
}

///\brief Shows players data
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



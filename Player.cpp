#include <string>
#include <utility>
#include "Player.h"
#include "Date.h"

using namespace std;
/// \brief Player constructor with the following« data
/// \param name Player's name
/// \param birth Player's birthday
/// \param club Player's club
/// \param weight Player's weight
/// \param height Player's height
/// \param value Player's value
/// \param insurance Player's insurance
Player::Player(string name, Date birth, string club, int weight, int height, int value, int insurance): Person(name, birth), club(club), weight(weight),
                                                                                                        height(height), value(value), insurance(insurance) {}
/// \brief Get Method
/// \return Player's club
string Player::getClub() const {
    return club;
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
int Player::getInsurance() const {
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
void Player::setInsurance(int insurance) {
    this -> insurance = insurance;
}
///\brief Shows players data
void Player::info() const
{
    Person::info();
    cout << "Club: " << getClub() << endl;
    cout << "Weight: " << getWeight() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Value: " << getValue() << endl;
    cout << "Insurance: " << getInsurance() << endl;
}




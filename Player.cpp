#include <string>
#include <utility>
#include "Player.h"
#include "Date.h"

using namespace std;
/// \brief Unary predicate for finding Players by name
/// \param p1 Pointer to first Player
/// \param p2 Pinter to second Player
/// \return true if both Players have the same name, false otherwise
bool cmp_player_by_name(Player *p1, Player *p2){
    return p1->getName() == p2->getName();
}
/// \brief Unary predicate for finding Players by position
/// \param p1 Pointer to first Player
/// \param p2 Pinter to second Player
/// \return true if both Players have the same position, false otherwise
bool cmp_player_by_position(Player *p1, Player *p2){
    return p1->getPosition() == p2->getPosition();
}

/// \brief Player constructor with the following« data
/// \param name Player's name
/// \param birth Player's birthday
/// \param club Player's club
/// \param weight Player's weight
/// \param height Player's height
/// \param value Player's value
/// \param insurance Player's insurance
Player::Player(string name, Date birth, string club, string position, int weight, int height, int value, int insurance): Person(name, birth), club(club), position(position),
                                                                                                                        weight(weight), height(height), value(value),
                                                                                                                        insurance(insurance) {}
/// \brief Get Method
/// \return Player's club
string Player::getClub() const {
    return club;
}

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
    cout << "Position: " << getPosition() << endl;
    cout << "Weight: " << getWeight() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Value: " << getValue() << endl;
    cout << "Insurance: " << getInsurance() << endl;
}
/// \brief Checks if Player's name is equal to the one given by parameter
/// \param p Compare with this Player's name
/// \return True if players have the same name, false otherwise
bool Player::operator==(const Player &p) {
    return getName() == p.getName();
}
/// \brief Checks if the parameter Player has the same name
/// \param p parameter of Player to compare name with
/// \return true if both Players have the same name, false otherwise
bool Player::equalName(Player p) const {
    return getName() == p.getName();
}
/// \brief Checks if the parameter Plauer has the same position
/// \param p Player parameter to compare positions with
/// \return true if both Players have the same position, false otherwise
bool Player::equalPosition(Player p) const {
    return getPosition() == p.getPosition();
}





#include <string>
#include <utility>
#include "Player.h"
#include "Date.h"

using namespace std;

Player::Player(string name, Date birth, enumPosition pos, string club, int weight, int height, int value, int insurance): Person(name,birth) {
    this -> pos = pos;
    this -> club = club;
    this -> weight = weight;
    this -> height = height;
    this -> value = value;
    this -> insurance = insurance;
}

Player::Player(string name, Date birth, enumPosition pos, string club, int weight, int height, int value) : Person(name,birth) {
    this -> pos = pos;
    this -> club = club;
    this -> weight = weight;
    this -> height = height;
    this -> value = value;
}

enumPosition Player::getPosition() const {
    return pos;
}

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

void Player::setPos(enumPosition pos) {
    this -> pos = pos;
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


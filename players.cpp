#include <string>
#include "player.h"

using namespace std;

Player::Player(string name, int bday, int bmonth, int byear, enumPosition pos, string club) : Person(string name, int bday, int bmonth, int byear), pos(pos), club(club) {}
#include <string>
#include "player.h"
#include "person.h"

using namespace std;

Player::Player(string name, int bday, int bmonth, int byear, enumPosition pos, string club) : Person(name, bday, bmonth, byear), pos(pos), club(club) {}

#include <string>
#include <utility>
#include "player.h"

using namespace std;

//Player::Player(string name, int bday, int bmonth, int byear, enumPosition pos, string club, int peso, int altura, int valor_passe, int seguro) : Person(std::move(name), bday, bmonth, byear), pos(pos), club(std::move(club)), peso(peso), altura(altura), valor_passe(valor_passe), seguro(seguro) {}

Player::Player(string name, int bday, int bmonth, int byear, enumPosition pos, string club, int peso, int altura, int valor_passe, int seguro): Person(name,bday,bmonth,byear) {

    this -> peso = peso;
    this -> altura = altura;
    this -> valor_passe = valor_passe;
    this -> seguro = seguro;


}

Player::Player(string name, int bday, int bmonth, int byear, enumPosition pos, string club) : Person(name,bday,bmonth,byear){

}

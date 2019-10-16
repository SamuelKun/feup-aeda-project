#include <iostream>

//
#include "string"
#include "Menus.h"
#include "Person.h"
#include "Player.h"
//

using namespace std;

int main() {

    //int sair = 1;

	//ZONA DE TESTE
	//Player cristiano("cristiano", 28, 06, 1980, Avancado, "fcp");
    //Este exemplo já n funciona pq se introduziu a classe date

	//
	/*
    try {
        while (sair != 0) {
            sair = menu_principal();
        }
    } catch (...) {
        cerr << "Ocorreu um erro..." << endl;
        return 1;
    }
    */
    while(!mainMenu());
    return 0;
}
#include <iostream>

//
#include "string"
#include "menus.h"
#include "person.h"
#include "player.h"
//

using namespace std;

int main() {

    int sair = 1;

	//ZONA DE TESTE
	Player cristiano("cristiano", 28, 06, 1980, Avancado, "fcp");


	//
    try {
        while (sair != 0) {
            sair = menu_principal();
        }
    } catch (...) {
        cerr << "Ocorreu um erro..." << endl;
        return 1;
    }
    
    return 0;
}
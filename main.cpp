#include <iostream>
#include "menus.h"

using namespace std;

int main() {

    int sair = 1;
    
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
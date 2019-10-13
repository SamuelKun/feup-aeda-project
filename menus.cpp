#include <iostream>
#include <string>
#include "menus.h"

using namespace std;

void ClearScreen() {
    cout << string(100, '\n');
}

int menu_principal() {

    int opcao_mp = 0;
    cout << "\t\t ========================================= " << endl;
    cout << "\t\t SELECAO NACIONAL MASCULINA FUTEBOL SENIOR " << endl;
    cout << "\t\t ========================================= \n" << endl;
    cout << "\t1. Visualizar informacoes jogadores" << endl;
    cout << "\t2. Visualizar informacoes equipa tecnica" << endl;
    cout << "\t3. Visualizar informacoes sobre a aplicacao" << endl;
    cout << "\t4. Sair" << endl;

    while (opcao_mp != 1 && opcao_mp != 2 && opcao_mp != 3 && opcao_mp != 4) {
        cin >> opcao_mp;
        if (opcao_mp != 1 && opcao_mp != 2 && opcao_mp != 3 && opcao_mp != 4) {
            cout << "\nInput invalido!" << endl;
        }
    }

    switch (opcao_mp) {
        case 1:
            opcao_mp = 0;
            ClearScreen();
            menu_jogadores();
            break;
        case 2:
            opcao_mp = 0;
            ClearScreen();
            menu_equipa_tecnica();
            break;
        case 3:
            opcao_mp = 0;
            ClearScreen();
            if (info_app() == 2) { return 0; }
            break;
        case 4:
            opcao_mp = 0;
            ClearScreen();
            return 0;
    }
    return 1;
}

int menu_jogadores() {
    return 0;
}

int menu_equipa_tecnica() {
   return 0; 
}

int info_app() {
    int opcao_info = 0;
    
    cout << "\nEsta aplicacao foi criada por:" << endl;
    cout << "\nDiogo Samuel";
    cout << "\nHugo Guimaraes";
    cout << "\nJoao Pires" << endl;

    cout << "\n1. Retroceder";
    cout << "\n2. Sair" << endl;

    while (opcao_info != 1 && opcao_info != 2) {
        cin >> opcao_info;
        if (opcao_info != 1 && opcao_info != 2) {
            cout << "\nInput invalido!";
        }
    }
    switch (opcao_info) {
        case 1:
            opcao_info = 0;
            ClearScreen();
            menu_principal();
            break;
        case 2:
            opcao_info = 0;
            ClearScreen();
            return 2;
    }

    return 1;
}


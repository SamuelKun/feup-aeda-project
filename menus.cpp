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
    //Em vez de fazeres este ciclo podias fazer default do switch case para chamar a própria funçcao de novo

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
int menu_info_app()
{
    char menu;

    cout << "This app was created by :" << endl << endl;
    cout << "Diogo Samuel Fernandes" << endl;
    cout << "Hugo Guimaraes" << endl;
    cout << "Joao Pires" << endl << endl;

    cout << "Press [1] to go back to the main menu" << endl;

    if (menu == '1') return 1;
    else
    {
        cin.ignore(1000,'\n');
        return 0;
    }

}

int menu_staff() {
    return 0;
}
int menu_players() {
    return 0;
}
int mainMenu()
{
    char menu;

    system("CLS");
    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "National Football Team " << endl;
    cout << "========================================= \n" << endl;
    cout << "1. View player info" << endl;
    cout << "2. View staff info" << endl;
    cout << "3. View app info" << endl;
    cout << "0. Exit" << endl;

    cin.clear();
    cin >> menu;

    switch(menu)
    {
        case '1':    //View player info
            while(!menu_players());
            break;
        case '2':    //View staff info
            while(!menu_staff());
            break;
        case '3':    //View app info
            while(!menu_info_app());
            break;
        case '0':    //Exit function
            return 1;
            break;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
            break;
    }


}



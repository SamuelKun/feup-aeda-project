#ifndef AEDA_INPUT_UTILS_H
#define AEDA_INPUT_UTILS_H

#include <iostream>



template <class form>
void failInput(form input) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        cin >> input;
    }
}

void waitInput() {
    string waiting;
    cout << "Press any key to continue: " << endl;
    getline(cin,waiting);
}

void checkPosition(string &position) {
    while(position != "Goalkeeper" && position != "Defender" &&
          position != "Midfielder" && position != "Forward") {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Not a valid position. Please reenter: " << endl;
        cout << "Goalkeeper/Defender/Midfielder/Forward" << endl;
        cin >> position;
    }
}

#endif //FEUP_AEDA_PROJECT_INPUT_UTILS_H

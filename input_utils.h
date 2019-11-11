#ifndef AEDA_INPUT_UTILS_H
#define AEDA_INPUT_UTILS_H

#include <iostream>
#include <string>

template <class form>
void failInput(form input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cin.ignore(1000, '\n');
        std::cout << "Not a valid number. Please reenter: ";
        std::cin >> input;
    }
}

void waitInput(){
    std::string waiting;
    std::cout << "Press any key to continue: " << std::endl;
    getline(std::cin,waiting);
}

void checkPosition(std::string &position){
    while(position != "Goalkeeper" && position != "Defender" &&
          position != "Midfielder" && position != "Forward"){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Not a valid position. Please reenter: " << std::endl;
        std::cout << "Goalkeeper/Defender/Midfielder/Forward" << std::endl;
        std::cin >> position;
    }
}

#endif //FEUP_AEDA_PROJECT_INPUT_UTILS_H

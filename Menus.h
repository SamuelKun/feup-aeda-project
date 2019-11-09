#include <iostream>
#include "Team.h"
using namespace std;


 /// \brief This menu shows the app creators
 /// \return Goes back to the main menu
int info_app();

 /// \brief All Staff Member information is here
 /// \return creates or views Staff Members, or returns to the main menu
int menu_staff();

 /// \brief All Player information is here
 /// \return creates or views Players, or returns to the main menu
int menu_players();

 /// \brief All Tournament information is here
 /// \return creates or views Tournaments, or returns to the main menu
int menu_tournaments();

 /// \brief This menu allows you to move between sub menus in order to use the app properly
 /// \return chooses between different menus or exiting the app
int mainMenu();

/// \brief Allows the user to open a .txt file referring to a team
/// \return Player/Staff/Tournaments Menus or App's info
int fileMenu();

/// \brief Menu that either allows the user to open a file or create a new one
/// \return Goes either to the File reading or File creating menus
int firstMenu();


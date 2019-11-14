#ifndef AEDA_MENUS_H
#define AEDA_MENUS_H

#include <string>

int menu_allPlayers();
/// \brief Menu for searching Players by Name or Position.
/// \return if 0, menu_searchPlayers(), menu_Players() otherwise
int menu_searchPlayers();
/// \brief All Player information is here.
/// \return if 0, menu_Players(), mainMenu() otherwise
int menu_players();
/// \brief Menu for searching Staff Members by Name or Position.
/// \return if 0, menu_searchStaffMembers(), menu_staff() otherwise
int menu_searchStaffMembers();
/// \brief All Staff Member information is here.
/// \return creates or views Staff Members, or returns to the main menu
int menu_staff();
/// \brief All Tournament information is here.
/// \return if 0, menu_tournaments(), mainMenu() otherwise
int menu_tournaments();
/// \brief All Games information is here.
/// \return if 0, menu_games(), menu_tournaments() otherwise
int menu_games();
/// \brief This menu indicates a Team's stats.
/// \return if 0, menu_info(), mainMenu() otherwise
int menu_info();
/// \brief This menu shows the app creators.
/// \return if 0, menu_credits(), mainMenu() otherwise
int menu_credits();
 /// \brief This menu allows you to move between sub menus in order to use the app properly.
 /// \return chooses between different menus or exiting the app
int mainMenu(std::string &file_name);
/// \brief Allows the user to open a .txt file referring to a team.
/// \return Player/Staff/Tournaments Menus or App's info
int fileMenu();
/// \brief Allows the user to create a new Team.
/// \return Goes back to initMenu
int createNewTeamMenu();
/// \brief Menu that either allows the user to open a file or create a new one.
/// \return if 0, InitMenu(), returns program otherwise
int initMenu();

#endif

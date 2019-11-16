#ifndef AEDA_MENUS_H
#define AEDA_MENUS_H

#include "Competition.h"
#include <string>
/// \brief A table with information of all players
/// \return if 0 menu opens again otherwise go back
int menu_allPlayers();
/// \brief Menu for searching Players by Name or Position.
/// \return if 0 menu opens again otherwise go back
int menu_searchPlayers();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_addPlayer();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_updatePlayers();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_removePlayer();
/// \brief All Player information is here.
/// \return if 0 menu opens again otherwise go back
int menu_players();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_allStaff();
/// \brief Menu for searching Staff Members by Name or Position.
/// \return if 0 menu opens again otherwise go back
int menu_searchStaffMembers();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_addStaff();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_updateStaff();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_removeStaff();
/// \brief All Staff Member information is here.
/// \return if 0 menu opens again otherwise go back
int menu_staff();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_searchGame();
/// \brief
/// \brief All Games information is here.
/// \return if 0 menu opens again otherwise go back
int menu_games();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_payCompetitions();
/// \brief All Tournament information is here.
/// \return if 0 menu opens again otherwise go back
int menu_competitionGames(Competition * comp);
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_calledCompetition(Competition* comp);
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_detailedCompetition(Competition * comp);
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_chooseCompetition();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_creatCompetition();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_updateCompetition();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_removeCompetition();
/// \brief
/// \return if 0 menu opens again otherwise go back
int menu_tournaments();
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

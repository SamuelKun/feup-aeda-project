#ifndef AEDA_MENUS_H
#define AEDA_MENUS_H

#include "Competition.h"
#include "DispTable.h"
#include <string>
/// \brief table with information of all players where is possible to sort
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_allPlayers();

/// \brief Menu for searching Players by Name or Position.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_searchPlayers();

/// \brief Menu to add a new Player
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_addPlayer();

/// \brief Menu to update Players
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_updatePlayers();

/// \brief Menu to remove players
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_removePlayer();

/// \brief All Player information is here.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_players();

/// \briefA table with information of all players where is possible to sort
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_allStaff();

/// \brief Menu for searching Staff Members by Name or Position.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_searchStaffMembers();

/// \brief Menu to add Staff members
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_addStaff();

/// \brief Menu to update Staff members
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_updateStaff();

/// \brief Menu to remove Staff members
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_removeStaff();

/// \brief All Staff Member information is here.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_staff();

/// \brief Menu to Search Games
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_searchGame();

/// \brief All Games information is here.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_games();

/// \brief Menu to pay competition fees to players
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_payCompetitions();

/// \brief Show games for one particular competition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_competitionGames(Competition * comp);

/// \brief Show called players in one competetition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_calledCompetition(Competition* comp);

/// \brief Show detailed information about one competition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_detailedCompetition(Competition * comp);

/// \brief Menu to select a competition to see deatailed information about
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_chooseCompetition();

/// \brief Menu to create a new Competition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_creatCompetition();

/// \brief Menu to update a Competition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_updateCompetition();

/// \brief Menu to remove a Competition
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_removeCompetition();

/// \brief This menu show Competition Information
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_tournaments();

/// \brief This menu indicates a Team's stats.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_info();

/// \brief This menu shows the app creators.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int menu_credits();

 /// \brief This menu allows you to move between sub menus in order to use the app properly.
 /// \return if 0 the menu is called again, 1 program ends
int mainMenu(std::string &file_name);

/// \brief Allows the user to open a .txt file referring to a team.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int fileMenu();

/// \brief Allows the user to create a new Team.
/// \return if 0 the menu is called again, 1 goes back to the previous menu
int createNewTeamMenu();

/// \brief Menu that either allows the user to open a file or create a new one.
/// \return if 0 the menu is called again, 1 program ends
int initMenu();
//Menus para a árvore binária

int menu_coach();
int menu_search_coach();
int menu_add_coach();
int menu_update_coach();
int menu_remove_coach();
//Menus para a tabela de disperção
int menuDispersionTable();
int menu_view_dispersion();
int menu_update_dispersion();
int menu_remove_dispersion();
int menu_add_dispersion();
#endif

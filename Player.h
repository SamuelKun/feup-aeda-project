#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

/*!
 * Class for a Player
 */
class Player : public Person
{
private:
	string club; //!*< Player's club.
	int weight;  //!*< Player's weight.
	int height;  //!*< Player's height.
	int value;   //!*< Player's value.
    int insurance; //!*< Player's insurance.
    //A calcular -> Nº dias do jogador na seleção * passe * 0.05;

public:
    //! A constructor.
    /*!
     * Creates a Player with the following data:
     * @param name Player's name.
     * @param birth Player's birth.
     * @param club Player's club.
     * @param weight Player's weight.
     * @param height Player's height.
     * @param value Player's value.
     * @param insurance Player's insurance.
     */
	Player(string name, Date birth, string club, int weight, int height, int value, int insurance = 0);
	//! A get member.
	/*!
	 *
	 * @return Player's Club.
	 */
	string getClub() const;
	//string pos; ARRANJAR MANEIRA DE FAZER ISTO DEPOIS
    //! A get member.
    /*!
     * @return Player's weight.
     */
	int getWeight() const;
    //! A get member.
    /*!
     * @return Player's height.
     */
	int getHeight() const;
    //! A get member.
    /*!
     * @return Player's value.
     */
	int getValue() const;
    //! A get member.
    /*!
     * @return Player's insurance.
     */
	int getInsurance() const;
    //! A set member
    /*!
     * Changes Player's club.
     * @param club Player's new club.
     */
	void setClub(string club);
    //! A set member
    /*!
     * Changes Player's weight.
     * @param club Player's new weight.
     */
	void setWeight(int weight);
    //! A set member
    /*!
     * Changes Player's height.
     * @param club Player's new height.
     */
	void setHeight(int height);
    //! A set member
    /*!
     * Changes Player's value.
     * @param club Player's new value.
     */
	void setValue(int value);
    //! A set member
    /*!
     * Changes Player's insurance.
     * @param club Player's new insurance.
     */
	void setInsurance(int insurance);
	//! A virtual member
	/*!
	 * Shows Player's info:
	 * Player's name.
     * Player's birth.
     * Player's club.
     * Player's weight.
     * Player's height.
     * Player's value.
     * Player's insurance.
	 */
    void info() const;

};

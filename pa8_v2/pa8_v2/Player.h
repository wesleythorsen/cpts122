/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Player.h"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Player class, inherits from Object class.
*              This is a class contain certian player information like score, and y axis movement, and sprite data.
*              Also contains member functions for controlling the player like jumping or changing the score.
*******************************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object
{
public:
	Player ();

	int getDeltaY () const {return _deltaY;}
	int getScore () const {return _score;}
	sf::RectangleShape getSprite () const {return _sprite;}

	void setDeltaY (int newDeltaY) {_deltaY = newDeltaY;}

	virtual void update ();
	virtual void updateSprite();

	void changeScore (int amount) {_score += amount;}
	void jump ();

private:
	double _deltaY;

	int _score;

	/* GRAPHICS PERSON: change the following sf::RectangleShape variable to a sprite var.
	                    This is what the game will draw at run time: */
	sf::RectangleShape _sprite;

};

#endif

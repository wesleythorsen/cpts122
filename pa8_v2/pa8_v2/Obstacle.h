/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Obstacle.h"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Obstacle class, inherits from Object class.
*              This is a class for the obstacles, contians info such as the obstacle's gap location and size, move speed, and the sprite info.
*              
*******************************************************************************************/

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Object.h"

class Obstacle : public Object
{
public:
	Obstacle ();
	~Obstacle ();

	int getGapY () const {return _gapY;}
	int getGapSize () const {return _gapSize;}
	sf::RectangleShape getTopBlock () const {return _blockTop;}
	sf::RectangleShape getBottomBlock () const {return _blockBottom;}

	virtual void update ();
	virtual void updateSprite();

private:
	int _gapY;
	int _gapSize;
	int _moveSpeed;

	/* GRAPHICS PERSON: change the following sf::RectangleShape variables to sprite vars.
	                    These are what the game will draw at run time: */
	sf::RectangleShape _blockTop;
	sf::RectangleShape _blockBottom;

};

#endif

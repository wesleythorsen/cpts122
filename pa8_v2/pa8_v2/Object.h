/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Object.h"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: This file contains class Object.
*              Object is a base class for other classes such as Player, Obstacle, and Enemy that are represented as objects in the game.
*              Contains several basic member variable (position X, size, etc...).
*              Also has getter and setter function for these variables.
*******************************************************************************************/

#ifndef OBJECT_H
#define OBJECT_H

#include "Header.h"

class Object
{
public:
	Object();

	int getPosX () const {return _posX;}
	int getPosY () const {return _posY;}
	int getSizeX () const {return _sizeX;}
	int getSizeY () const {return _sizeY;}

	void setPosX (int newX) {_posX = newX;}
	void setPosY (int newY) {_posY = newY;}
	void setSizeX (int newX) {_sizeX = newX;}
	void setSizeY (int newY) {_sizeY = newY;}

	virtual void update () = 0;
	virtual void updateSprite() = 0;

	int randInt (int min, int max);

private:
	int _posX;
	int _posY;
	int _sizeX;
	int _sizeY;

};

#endif

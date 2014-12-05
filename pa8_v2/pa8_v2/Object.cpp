/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Object.cpp"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Contians function definitions for the Object base class.
*              
*              
*******************************************************************************************/

#include "Object.h"

Object::Object ()
{

}

int Object::randInt (int min, int max)
{
	int randNumb;

	randNumb = rand() % (max - min);
	randNumb += min;

	return randNumb;
}
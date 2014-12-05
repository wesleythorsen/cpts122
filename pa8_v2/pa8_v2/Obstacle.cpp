/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Obstacle.cpp"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Contians function deffinitions for the Obstacle class.
*              Obstacle physics are located in the update() function.
*              
*******************************************************************************************/

#include "Obstacle.h"

/***********************************
* Function: Obstacle::Obstacle()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Initializes obstacle object.
*              No parameters.
************************************/
Obstacle::Obstacle () : _gapSize(200), _moveSpeed(2)
{
	setPosX  ( 800 );
	setPosY  ( 0   );
	setSizeX ( 75  );
	setSizeY ( 0   );

	_gapY = randInt ( _gapSize + 50, 550 );

	/* GRAPHICS PERSON: Change the code below for sprites. It is currently set up
	                    for rectangle shapes */
	_blockTop.setFillColor ( sf::Color::White );
	_blockBottom.setFillColor ( sf::Color::White );

	_blockTop = sf::RectangleShape( sf::Vector2f( getSizeX(), ( _gapY - _gapSize ) ) );
	_blockTop.setPosition ( getPosX(), 0 );
	_blockBottom = sf::RectangleShape( sf::Vector2f ( getSizeX(), ( 600 - _gapY ) ) );
	_blockBottom.setPosition ( getPosX(), _gapY );
}




/***********************************
* Function: Obstacle::update()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Updates obstacle objects (location).
*              No parameters.
************************************/
void Obstacle::update ()
{
	setPosX ( getPosX() - _moveSpeed );
}




/***********************************
* Function: Obstacle::updateSprite()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Updates obstacle's sprite location.
*              No parameters.
************************************/
void Obstacle::updateSprite ()
{
	_blockTop.setPosition ( getPosX(), 0 );
	_blockBottom.setPosition ( getPosX(), _gapY );
}
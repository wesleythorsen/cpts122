/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Player.cpp"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Contians function definitions for the Player class.
*              the update() function is where the player physics are located.
*              
*******************************************************************************************/

#include "Player.h"

/***********************************
* Function: Player::Player()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Initializes player object.
*              No parameters.
************************************/
Player::Player () : _deltaY(0), _score(0),
	_sprite( sf::Vector2f ( 20, 20 ) )
{
	setPosX  ( 390 );
	setPosY  ( 150 );
	setSizeX ( 20  );
	setSizeY ( 20  );

	_sprite.setFillColor ( sf::Color::White );
}




/***********************************
* Function: Player::update()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Updates player position and velocity.
*              No parameters.
************************************/
void Player::update ()
{
	_deltaY += 0.75;
	setPosY ( _deltaY + getPosY() );
}




/***********************************
* Function: Player::updateSprite()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Updates player's sprite position.
*              No parameters.
************************************/
void Player::updateSprite ()
{
	_sprite.setPosition ( getPosX(), getPosY() );/* update sprite position */
}




/***********************************
* Function: Player::jump()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Changes player velocity upwards.
*              No parameters.
************************************/
void Player::jump ()
{
	_deltaY = -14;
}
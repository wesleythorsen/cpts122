/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Game.cpp"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Contians function deffinitions for the Game class.
*              These include functions contain the some initialization instructions, the main game loop, event checking code,
*              game process updating code, and screen drawing code.
*******************************************************************************************/

#include "Game.h"

/***********************************
* Function: Game::Game()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Basic constructor, no parameters.
*              Sets frame rate to 60 (project default).
************************************/
Game::Game () : _pRunning(true), _winSizeX(800), _winSizeY(600),
	_window(sf::VideoMode(800, 600), "Game Window"),
	_timer(0)
{
	_window.setVerticalSyncEnabled(false); /* DO NOT change this to true, interacts badly with setFrameRateLimit() function. */
	_window.setFramerateLimit(60); /* set framerate to 60 frames per second (project default, don't change) */
}




/***********************************
* Function: Game::run()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Main game loop. Controls the execution of the game functions (events, updating, drawing)
*              No parameters.
************************************/
void Game::run ()
{
	/* This is the main game loop: */
	while (_pRunning)
	{
		this->checkEvent();/* checks for keyboard/mouse/joystic events */
		
		_window.clear(sf::Color::Black);


		this->update();/* updates things like player position, obstacle position, 
					   timers, collision detection. Not for drawing to the window,
					   only for updating numbers and game math */
		this->draw();/*  */

		_window.display();
	}

}




/***********************************
* Function: Game::checkEvent()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Collects keyboard/mouse events between loop cycles, takes action as defined here.
*              No parameters.
************************************/
void Game::checkEvent ()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)/* Window close button is pressed */
		{
			_pRunning = false;/* _pRunning controlls the main loop. This line ends the main loop */
			_window.close();/* this line closes the Render Window */
		}

		/* Keyboard/Mouse events go here: */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_player.jump();/* gives the player upward velocity */
		}
		/*Example: (not needed in game)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_player.setPosY( _player.getPosY() - 50);//moves player up
		}*/


	}

}




/***********************************
* Function: Game::update()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Updates game parameters, objects info, player data etc.
*              Does not draw anything to the screen, only updates numbers and does game math(collision detection).
*              No parameters.
************************************/
void Game::update ()
{
/* Timers: */
	_timer++;/* increment timer by 1 each loop cycle ( 60 frames(loops) per second ) */
	if (_timer >= 1800) /* _timer resets every 30 seconds (1800frames = 60fps * 30seconds) */
	{
		_timer = 0;
	}

	/*Example:
	if ( !( _timer % number of frames to repeat) )
	{
		do code here.
	}
	*/

	if ( !( _timer % 120 ) )/* if _timer is a multiple of 120 (once every 2 seconds),
						   Do the following: */
	{
		_obstacleList.push_back(new Obstacle);/* Create new obstacle once every 2 seconds */

	}

/* Update Player: */
	_player.update(); /* player physics */


/* Update Obstacles: */
	for (int i = 0; i < _obstacleList.size(); i++) /* for every obstacle in _obstacleList (all obstacles on screen): */
	{
		_obstacleList[i]->update();/* update obstacle info (move position) */

		/* if an obstacle goes off screen: */
		if (_obstacleList[i]->getPosX() < ( 0 - _obstacleList[i]->getSizeX() ))
		{
			_obstacleList.erase (_obstacleList.begin() + i); /* delete it */
		}
	}


/* Spatial Detection: */

	/* Player-Window collision detection: */
	/* if player hits the: */
	if ( _player.getPosY() < 0 )/* top of the screen */
	{
		_player.setDeltaY ( 0 );/* stop them from moving up */
		_player.setPosY ( 0 );
	}
	else if ( _player.getPosY() > ( _winSizeY - _player.getSizeY() ) )/* bottom of the screen */
	{
		_player.setDeltaY ( 0 );/* stop them from moving down */
		_player.setPosY ( _winSizeY - _player.getSizeY() );
	}


	/* Obstacle-Player collision detection: */
	for (int i = 0; i < _obstacleList.size(); i++)
	{

		if (/* test for x axis overlap:
			 if right edge of player is to the right of the left edge of the obstacle: */
			( ( _player.getPosX() + _player.getSizeX() ) >= _obstacleList[i]->getPosX() )
			/* AND */
			&&
			/* if left edge of player is to the left of the right edge of the obstacle */
			( _player.getPosX() <= ( _obstacleList[i]->getPosX() + _obstacleList[i]->getSizeX() ) ))
		{

			/* if the above is true, then x axis' are overlaped. Now check the y axis': */

			if (/* test y axis overlap for top obstacle:
				 if top edge of player is above the bottom edge of top obstacle */
				_player.getPosY() <= ( _obstacleList[i]->getGapY() - _obstacleList[i]->getGapSize() )
			   )
			{
				/* There is a collision with upper obstacle! 
				insert collision code here:*/

			}
			else if ( ( _player.getPosY() + _player.getSizeY() ) >= _obstacleList[i]->getGapY() )/*test y axis overlap for bottom obstacle*/
			{
				/* there is a collision lower obstacle!
				insert collision code here:*/

			}
		}
	}


/* Update Sprites: */

	/* do this last once all the position calculations are done */

	/* Player Sprite: */
	_player.updateSprite();

	/* Obstacle Sprite: */
	for (int i = 0; i < _obstacleList.size(); i++)
	{
		_obstacleList[i]->updateSprite();
	}

}




/***********************************
* Function: Game::draw()
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Draws objects and other entities to the render window
*              No parameters.
************************************/
void Game::draw ()
{
	/* Draw Player: */
	_window.draw( _player.getSprite() );

	/* Draw Obstacles: */
	for (int i = 0; i < _obstacleList.size(); i++)/* for every obstacle (all obstacles on screen): */
	{
		_window.draw( _obstacleList[i]->getTopBlock() );
		_window.draw( _obstacleList[i]->getBottomBlock() );
	}
}

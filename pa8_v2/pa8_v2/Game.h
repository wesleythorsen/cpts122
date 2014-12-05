/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Game.h"
* Programmers: Wesley Thorsen
*              
*              
*              
* Description: Game class. Contains member functions for the main game loop, event checking, updating game related things, and drawing to the screen.
*              Contains variables such as the Render Window, the Player, a list of Obstacles, and a timer varible.
*              The Game constructor initializes the Render Window and sets certian variables to there initial values.
*******************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Obstacle.h"

class Game
{
public:
	Game ();

	void run ();

	void checkEvent ();
	void update ();
	void draw ();

private:
	bool _pRunning;

	sf::RenderWindow _window;
	int _winSizeX;
	int _winSizeY;

	Player _player;
	std::vector <Obstacle*> _obstacleList;
	
	int _timer;

};

#endif
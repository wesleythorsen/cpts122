/*******************************************************************************************
* Assignment:  pa_8 - Game Program
* File:        "Source.cpp"
* Programmers: Wesley Thorsen
*              Zachary Edwards
*              Emily Dreke
*              Steven Peyron
* Description: Contains main() funtion.
*              Creates a new game element and runs it.
*              Also seeds random.
*******************************************************************************************/

#include "Game.h"

int main ()
{
	Game G;
	
	srand(time(NULL));/* seed random */
	
	G.run();/* start main game loop */
}
//#include <SFML/Graphics.hpp>
//#include <stdlib.h>//random
#include <Windows.h>//get current dir windows

#include "Game.h"
#include "GameState.h"
#include "GameStateTest.h"
#include "GameStateLevel.h"

//#include "ParticaleSystem.h"
//class ParticleSystem;

int main()
{
	/*float a = 180;
	for (int i = 0; i<20; i++)
		printf("%f\n", ((float)rand() / (float)(RAND_MAX)) * a + 180);*/

	char path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, path);
	std::cout << "Current Directory = " << path << std::endl;

	Game game;

	game.gameState.push(new GameStateLevel(&game));
	
	game.run();

	return 0;
}

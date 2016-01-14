#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "constants.h"
#include "game.h"

using namespace sf;
using namespace std;

void StartGame()
{
	RenderWindow window (VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	Game* game = new Game;
	game->InitGame(window);
	while (window.isOpen())
	{
		game->UpdateGame(window);
		window.clear();
		game->DrawWindow(window);
		window.display();
	}
	delete game;
}

int main()
{
	StartGame();
	return 0;
}

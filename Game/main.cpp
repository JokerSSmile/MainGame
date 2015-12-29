#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "collision.h"
#include "constants.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "chest.h"
#include "sprites.h"
#include "game.h"
#include "menu.h"

using namespace sf;
using namespace std;

//TODO: sound when bomb exploded

void StartGame()
{
	RenderWindow window (VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	Game* game = new Game;
	game->InitGame();
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

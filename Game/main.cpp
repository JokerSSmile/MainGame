#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "collision.h"
#include "constants.h"
#include "map.h"
#include "view.h"
#include "player.h"
#include "enemy.h"
#include "chest.h"
#include "sprites.h"
#include "game.h"

using namespace sf;
using namespace std;

//TODO: 
//звук

void ProcessEvents(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void StartGame()
{
	Game* game = new Game;
	RenderWindow window (VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	game->InitGame();
	view.reset(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	while (window.isOpen())
	{
		float time = game->clock.getElapsedTime().asMicroseconds();
		game->clock.restart();
		time = time / 500;

		ProcessEvents(window);
		game->UpdateGame(time, view, window);

		window.setView(view);
		window.clear();
		game->DrawWindow(view, time, window);
		window.display();
	}
	delete game;
}

int main()
{
	StartGame();
	return 0;
}

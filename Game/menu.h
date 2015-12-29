#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "constants.h"

#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

struct MainMenu
{
	Sprite menuSprite;
	Sprite startButtonSprite;

	Text startText;
	Text exitText;

	void InitMenu(Texture& menuTexture, Font& font);
	void Update(int& volume, View& view);
	void CheckCollisionWithMouse(RenderWindow& window, GameState& gameState, Event& event);
	void Draw(RenderWindow& window, GameState& gameState, Event& event);
};
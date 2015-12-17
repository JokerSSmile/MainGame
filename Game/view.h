#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

View view;

void GetPlayerCoordinateForView(float x, float y)
{
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	if (x < 480) tempX = 480;//убираем из вида левую сторону
	if (y < 320) tempY = 320;//верхнюю сторону
	if (y > 320) tempY = 320;//нижнюю сторону	
	if (x > 480) tempX = 480;

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты
}
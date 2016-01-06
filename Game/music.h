#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "constants.h"

using namespace sf;
using namespace std;

static enum
{
	FIRST_MUSIC,
	SECOND_MUSIC,
	THIRD_MUSIC
} currentMusic;

struct Sounds
{
	//int currentMusic;

	Music backgroundMusic1;
	Music backgroundMusic2;
	Music backgroundMusic3;

	Music menuMusic;

	SoundBuffer tearDestroyBuffer;
	Sound tearDestroy;

	SoundBuffer bombExplosionBuffer;
	Sound  bombExplosion;

	SoundBuffer chestOpeningBuffer;
	Sound chestOpening;

	SoundBuffer doorOpeningBuffer;
	Sound doorOpening;

	SoundBuffer playerHurtsBuffer;
	Sound playerHurts;

	SoundBuffer chestDropBuffer;
	Sound chestDrop;
	
	void LoadMusic();
	void SetVolume(int& volume);
	void UpdateMusic(int& volume);
};

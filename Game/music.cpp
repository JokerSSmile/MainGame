#include "music.h"

void Sounds::LoadMusic()
{
	backgroundMusic1.openFromFile("resources/music/background1.ogg");
	backgroundMusic2.openFromFile("resources/music/background2.ogg");
	backgroundMusic3.openFromFile("resources/music/background3.ogg");

	menuMusic.openFromFile("resources/music/main_menu.ogg");

	currentMusic = FIRST_MUSIC;
	//backgroundMusic1.play();

	tearDestroyBuffer.loadFromFile("resources/sound/tear_destroy.wav");
	tearDestroy.setBuffer(tearDestroyBuffer);

	bombExplosionBuffer.loadFromFile("resources/sound/bomb_explosion.wav");
	bombExplosion.setBuffer(bombExplosionBuffer);

	chestOpeningBuffer.loadFromFile("resources/sound/chest_drop.wav");
	chestOpening.setBuffer(chestOpeningBuffer);

	doorOpeningBuffer.loadFromFile("resources/sound/door_open.wav");
	doorOpening.setBuffer(doorOpeningBuffer);

	playerHurtsBuffer.loadFromFile("resources/sound/player_hurts.wav");
	playerHurts.setBuffer(playerHurtsBuffer);

}

void Sounds::UpdateMusic()
{
	if (backgroundMusic1.getStatus() == false && currentMusic == FIRST_MUSIC)
	{
		//backgroundMusic2.play();
		currentMusic = SECOND_MUSIC;
	}
	else if (backgroundMusic2.getStatus() == false && currentMusic == SECOND_MUSIC)
	{
		//backgroundMusic3.play();
		currentMusic = THIRD_MUSIC;
	}
	else if (backgroundMusic3.getStatus() == false && currentMusic == THIRD_MUSIC)
	{
		//backgroundMusic1.play();
		currentMusic = FIRST_MUSIC;
	}
}

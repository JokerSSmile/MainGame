#include "music.h"

void Sounds::LoadMusic()
{
	backgroundMusic1.openFromFile("resources/music/background1.ogg");
	backgroundMusic2.openFromFile("resources/music/background2.ogg");
	backgroundMusic3.openFromFile("resources/music/background3.ogg");

	menuMusic.openFromFile("resources/music/main_menu.ogg");
	menuMusic.setLoop(true);

	bossMusic.openFromFile("resources/music/boss_fight.ogg");
	bossMusic.setLoop(true);

	tearDestroyBuffer.loadFromFile("resources/sound/tear_destroy.wav");
	tearDestroy.setBuffer(tearDestroyBuffer);

	bombExplosionBuffer.loadFromFile("resources/sound/bomb_explosion.wav");
	bombExplosion.setBuffer(bombExplosionBuffer);

	chestDropBuffer.loadFromFile("resources/sound/chest_drop.wav");
	chestDrop.setBuffer(chestDropBuffer);

	chestOpeningBuffer.loadFromFile("resources/sound/chest_open.wav");
	chestOpening.setBuffer(chestOpeningBuffer);

	doorOpeningBuffer.loadFromFile("resources/sound/door_open.wav");
	doorOpening.setBuffer(doorOpeningBuffer);

	playerHurtsBuffer.loadFromFile("resources/sound/player_hurts.wav");
	playerHurts.setBuffer(playerHurtsBuffer);

	tearFireBuffer.loadFromFile("resources/sound/tear_fire.wav");
	tearFire.setBuffer(tearFireBuffer);

	flyHurtBuffer.loadFromFile("resources/sound/fly_hurt.wav");
	flyHurt.setBuffer(flyHurtBuffer);

	enemyHurtBuffer.loadFromFile("resources/sound/enemy_hurt.wav");
	enemyHurt.setBuffer(enemyHurtBuffer);

	bossLandsBuffer.loadFromFile("resources/sound/boss_lands.wav");
	bossLands.setBuffer(bossLandsBuffer);

	bossShootsBoofer.loadFromFile("resources/sound/boss_shoots.wav");
	bossShoots.setBuffer(bossShootsBoofer);

	bossDiesBuffer.loadFromFile("resources/sound/boss_dies.wav");
	bossDies.setBuffer(bossDiesBuffer);
}

void Sounds::SetVolume(int& volume)
{
	backgroundMusic1.setVolume(float(volume / 2));
	backgroundMusic2.setVolume(float(volume / 2));
	backgroundMusic3.setVolume(float(volume / 2));
	tearDestroy.setVolume(float(volume));
	bombExplosion.setVolume(float(volume));
	chestDrop.setVolume(float(volume));
	chestOpening.setVolume(float(volume));
	doorOpening.setVolume(float(volume));
	playerHurts.setVolume(float(volume));
	flyHurt.setVolume(float(volume));
	enemyHurt.setVolume(float(volume));
	tearFire.setVolume(float(volume));
	menuMusic.setVolume(float(volume / 2));
	bossMusic.setVolume(float(volume / 2));
}

void Sounds::UpdateMusic(int& volume, Level& level)
{
	SetVolume(volume);
	if (level != BOSS)
	{
		if (backgroundMusic1.getStatus() == false && currentMusic == FIRST_MUSIC)
		{
			backgroundMusic2.play();
			currentMusic = SECOND_MUSIC;
		}
		else if (backgroundMusic2.getStatus() == false && currentMusic == SECOND_MUSIC)
		{
			backgroundMusic3.play();
			currentMusic = THIRD_MUSIC;
		}
		else if (backgroundMusic3.getStatus() == false && currentMusic == THIRD_MUSIC)
		{
			backgroundMusic1.play();
			currentMusic = FIRST_MUSIC;
		}
	}
	else
	{
		if (bossMusic.getStatus() == false)
		{
			bossMusic.play();
		}
	}
}

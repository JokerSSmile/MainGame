#include "music.h"

const String BACKGORUND_MUSIC_1 = "resources/music/background1.ogg";
const String BACKGORUND_MUSIC_2 = "resources/music/background2.ogg";
const String BACKGORUND_MUSIC_3 = "resources/music/background3.ogg";
const String TEARS_DESTROY_SOUND = "resources/sound/tear_destroy.wav";
const String BOMB_EXPLOSION_SOUND = "resources/sound/bomb_explosion.wav";
const String CHEST_OPENING_SOUND = "resources/sound/chest_open.wav";
const String DOOR_OPENING_SOUND = "resources/sound/door_open.wav";
const String PLAYER_HURTS_SOUND = "resources/sound/player_hurts.wav";
const String CHEST_DROP_SOUND = "resources/sound/chest_drop.wav";
const String MAIN_MENU_MUSIC = "resources/music/main_menu.ogg";

void Sounds::LoadMusic()
{
	backgroundMusic1.openFromFile(BACKGORUND_MUSIC_1);
	backgroundMusic2.openFromFile(BACKGORUND_MUSIC_2);
	backgroundMusic3.openFromFile(BACKGORUND_MUSIC_3);

	tearDestroyBuffer.loadFromFile(TEARS_DESTROY_SOUND);
	tearDestroy.setBuffer(tearDestroyBuffer);

	bombExplosionBuffer.loadFromFile(BOMB_EXPLOSION_SOUND);
	bombExplosion.setBuffer(bombExplosionBuffer);

	chestDropBuffer.loadFromFile(CHEST_DROP_SOUND);
	chestDrop.setBuffer(chestDropBuffer);

	chestOpeningBuffer.loadFromFile(CHEST_OPENING_SOUND);
	chestOpening.setBuffer(chestOpeningBuffer);

	doorOpeningBuffer.loadFromFile(DOOR_OPENING_SOUND);
	doorOpening.setBuffer(doorOpeningBuffer);

	playerHurtsBuffer.loadFromFile(PLAYER_HURTS_SOUND);
	playerHurts.setBuffer(playerHurtsBuffer);

	menuMusic.openFromFile(MAIN_MENU_MUSIC);
	menuMusic.setLoop(true);
}

void Sounds::SetVolume(int& volume)
{
	backgroundMusic1.setVolume(volume / 2);
	backgroundMusic2.setVolume(volume / 2);
	backgroundMusic3.setVolume(volume / 2);
	tearDestroy.setVolume(volume);
	bombExplosion.setVolume(volume);
	chestDrop.setVolume(volume);
	chestOpening.setVolume(volume);
	doorOpening.setVolume(volume);
	playerHurts.setVolume(volume);
	menuMusic.setVolume(volume);
}

void Sounds::UpdateMusic(int& volume)
{
	SetVolume(volume);
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

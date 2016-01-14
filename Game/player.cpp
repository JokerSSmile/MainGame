#include "player.h"

#include "collision.h"


void Player::setFrame(float& time)
{
	CurrentFrame += 0.005f * time;
	if (CurrentFrame > 4) CurrentFrame -= 4;
}

bool Player::DiagonalMoving(float& time)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = LEFT_UP;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = LEFT_DOWN;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = RIGHT_UP;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = RIGHT_DOWN;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
		return true;
	}
	return false;
}

void Player::StrightMoving(float& time)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		dir = LEFT;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		dir = RIGHT;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = UP;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 0, 36, 26));
		headSprite.setTextureRect(IntRect(128, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = DOWN;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 0, 36, 26));
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	else
	{
		dir = STAND;
		sprite.setTextureRect(IntRect(0, 0, 36, 26));
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
}

void Player::MakeShoot(vector<Bullet>& bullets, float gameTime, float &lastShot, Sound& tearFire)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 4, tearFire);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		headSprite.setTextureRect(IntRect(128, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 5, tearFire);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 6, tearFire);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 7, tearFire);
	}
}

void Player::PlantBomb(Boomb& bomb, float& time)
{
	if (bombCount > 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (time > lastBombPlant + TIME_BEFORE_EXPLOSION + TIME_FOR_EXPLOSION || lastBombPlant == 0)
			{
				lastBombPlant = time;
				bomb.position = Vector2f(position.x - size.y / 2, position.y - size.y / 2);
				bomb.createTime = time;
				bomb.explosionTime = time + TIME_BEFORE_EXPLOSION;
				bomb.isAlive = true;
				bombCount--;
			}
		}
	}
}

void Player::Control(Boomb& bomb, vector<Bullet>& bullets, float& time, float& gameTime, float &lastShot, Sound& tearFire)
{
	if (DiagonalMoving(time) == false)
	{
		StrightMoving(time);
	}
	MakeShoot(bullets, gameTime, lastShot, tearFire);
	PlantBomb(bomb, gameTime);
}

void Player::SetShootAnimation(int& dir)
{
	if (dir == 0 || dir == 1 || dir == 4)
	{
		headSprite.setTextureRect(IntRect(224, 0, 32, 32));
	}
	else if (dir == 2 || dir == 3 || dir == 7)
	{
		headSprite.setTextureRect(IntRect(96, 0, 32, 32));
	}
	else if (dir == 5)
	{
		headSprite.setTextureRect(IntRect(160, 0, 32, 32));
	}
	else if (dir == 6 || dir == 8)
	{
		headSprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
}

void Player::Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir, Sound& tearFire)
{
	if (gameTime > (lastShootPlayer + timeBetweenShoots))
	{
		Bullet bullet;
		bullet.isPlayers = true;
		bullet.alive = true;
		if (dir == 5)
		{
			bullet.position.y = headSprite.getPosition().y + headSprite.getLocalBounds().height / 2 - BULLET_SHIFT_IF_SHOOT_UP;
		}
		else
		{		
			bullet.position.y = headSprite.getPosition().y + headSprite.getLocalBounds().height / 2;
		}
		bullet.position.x = headSprite.getPosition().x + headSprite.getLocalBounds().width / 2;
		bullet.timeShot = gameTime;
		bullet.direction = dir;
		bullet.speed = PLAYERS_BULLET_SPEED;
		bullet.damage = damage;
		bullet.startPos = position;
		bullet.isDel = false;
		lastShootPlayer = bullet.timeShot;
		bullets.push_back(bullet);
		tearFire.play();
	}
	if (gameTime < lastShootPlayer + TIME_FOR_SHOOT_ANIMATION)
	{
		SetShootAnimation(dir);
	}
}

bool Player::IsIntersectsPlayerEnemy(Enemy& enemy)
{
	if (Collision::PixelPerfectTest(sprite, enemy.sprite) || Collision::PixelPerfectTest(headSprite, enemy.sprite))
	{
		return true;
	}
	return false;
}

void Player::CheckEnemyCollidesPlayer(vector<Enemy>& enemies, Boss& boss, float& gameTime, Sound& playerHurts)
{
	for (auto& enemy: enemies)
	{
		if (enemy.alive == true && enemy.sprite.getPosition().x != 0)
		{
			if (IsIntersectsPlayerEnemy(enemy) && (gameTime > hitTimer + TIME_FOR_PLAYER_HIT_CD || hitTimer == 0))
			{
				cout << enemy.health << endl;
				health -= enemy.damage;
				hitTimer = gameTime;
				playerHurts.play();

			}
		}
	}
	if (Collision::PixelPerfectTest(sprite, boss.sprite) && (gameTime > hitTimer + TIME_FOR_PLAYER_HIT_CD || hitTimer == 0))
	{
		if (boss.state == SHOOT || boss.state == STAY && boss.alive == true)
		{
			health -= BOSS_FALL_DAMAGE;
			hitTimer = gameTime;
			playerHurts.play();
		}
	}
}

void Player::ChangeColorAfterHit(float& gameTime)
{
	if ((gameTime > hitTimer && gameTime < hitTimer + CHANGE_COLOR_EFFECT) || (gameTime > lastHitTime && gameTime < lastHitTime + CHANGE_COLOR_EFFECT)
		|| gameTime > bombHitTime && gameTime < bombHitTime + CHANGE_COLOR_EFFECT)
	{
		if (gameTime > 1)
		{
			sprite.setColor(Color(COLOR_AFTER_HIT));
			headSprite.setColor(Color(COLOR_AFTER_HIT));
		}
	}
	else
	{
		sprite.setColor(Color::White);
		headSprite.setColor(Color::White);
	}
}

void Player::DoorCollision(vector<Map>& myMap, View& view, bool& areDoorsOpened)
{
	for (auto&map : myMap)
	{
		if (areDoorsOpened == true && Collision::PixelPerfectTest(sprite, map.sprite))
		{
			if (map.pos == D_RIGHT)
			{
				view.setCenter(view.getCenter().x + WINDOW_WIDTH, view.getCenter().y);
				position.x += TILE_SIDE * 4 + size.x + 10;
			}
			else if (map.pos == D_LEFT)
			{
				view.setCenter(view.getCenter().x - WINDOW_WIDTH, view.getCenter().y);
				position.x -= TILE_SIDE * 4 + size.x + 10;
			}
			else if (map.pos == D_UP)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y - WINDOW_HEIGHT);
				position.y -= TILE_SIDE * 4 + size.y + 10;
			}
			else if (map.pos == D_DOWN)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y + WINDOW_HEIGHT);
				position.y += TILE_SIDE * 4 + size.y + 10;
			}
			break;
		}
	}
}

void Player::SpikeCollision(vector<Map>& myMap, float& gameTime, Sound& playerHurts)
{
	for (auto& map : myMap)
	{
		if (Collision::PixelPerfectTest(sprite, map.sprite) && gameTime > hitTimer + TIME_FOR_PLAYER_HIT_CD)
		{
			if (map.pos == SPIKE)
			{
				health -= SPIKE_DAMAGE;
				hitTimer = gameTime;
				playerHurts.play();
			}
			break;
		}
	}
}

bool Player::IsIntersectsMap(vector<Map>& myMap, View& view, bool areDoorsOpened)
{
	for (auto& map : myMap)
	{
		if (Collision::BoundingBoxTest(sprite, map.sprite))
		{
			if (map.pos == WALL || map.pos == ROCK)
			{
				return true;
			}
		}
	}
	return false;
}

void Player::CheckExplosionCollision(Boomb& boomb, float& gameTime, Sound& playerHurts)
{
	if (sprite.getGlobalBounds().intersects(boomb.damageZone.getGlobalBounds()) || headSprite.getGlobalBounds().intersects(boomb.damageZone.getGlobalBounds()))
	{
		if (gameTime > bombHitTime + TIME_BEFORE_EXPLOSION && gameTime < boomb.explosionTime + 0.5)
		{
			health -= BOMB_DAMAGE;
			bombHitTime = gameTime;
			playerHurts.play();
		}
	}
}

void Player::Moving(float& time, vector<Map>& myMap, View& view, bool areDoorsOpened, Sprite& wallSprite)
{
	DoorCollision(myMap, view, areDoorsOpened);
	Vector2f playerOldPosition = sprite.getPosition();
	SetPosition(time, speed);
	sprite.setPosition(position);
	if (IsIntersectsMap(myMap, view, areDoorsOpened) == true || Collision::PixelPerfectTest(sprite, wallSprite))
	{
		sprite.setPosition(playerOldPosition);
		if (position.x != playerOldPosition.x && position.y != playerOldPosition.y)
		{
			sprite.setPosition(playerOldPosition.x, position.y);
			if (IsIntersectsMap(myMap, view, areDoorsOpened) == true || Collision::PixelPerfectTest(sprite, wallSprite))
			{
				sprite.setPosition(position.x, playerOldPosition.y);
				if (IsIntersectsMap(myMap, view, areDoorsOpened) == true || Collision::PixelPerfectTest(sprite, wallSprite))
				{
					sprite.setPosition(playerOldPosition);
				}
			}
		}
	}
	position = sprite.getPosition();
	headSprite.setPosition(sprite.getPosition().x - SHIFT_FOR_HEAD.x, sprite.getPosition().y - SHIFT_FOR_HEAD.y);
}
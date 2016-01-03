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
		dir = leftUp;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = leftDown;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = rightUp;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = rightDown;
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
		dir = left;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		dir = right;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = up;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 0, 36, 26));
		headSprite.setTextureRect(IntRect(128, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = down;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 0, 36, 26));
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	else
	{
		dir = stay;
		sprite.setTextureRect(IntRect(0, 0, 36, 26));
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
}

void Player::MakeShoot(vector<Bullet>& bullets, float gameTime, float &lastShot)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 4);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		headSprite.setTextureRect(IntRect(128, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 5);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		headSprite.setTextureRect(IntRect(0, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 6);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
		Shoot(bullets, gameTime, lastShot, 7);
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
				bomb.position = Vector2f(position.x - h / 2, position.y - h / 2);
				bomb.createTime = time;
				bomb.explosionTime = time + TIME_BEFORE_EXPLOSION;
				bomb.isAlive = true;
				bombCount--;
			}
		}
	}
}

void Player::Control(Boomb& bomb, vector<Bullet>& bullets, float& time, float& gameTime, float &lastShot)
{
	if (DiagonalMoving(time) == false)
	{
		StrightMoving(time);
	}
	MakeShoot(bullets, gameTime, lastShot);
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

void Player::Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir)
{
	if (gameTime > (lastShootPlayer + TIME_BETWEEN_SHOOTS_PLAYER))
	{
		Bullet bullet;
		bullet.isPlayers = true;
		bullet.alive = true;
		if (dir == 5)
		{
			bullet.y = headSprite.getPosition().y + headSprite.getLocalBounds().height / 2 - BULLET_SHIFT_IF_SHOOT_UP;
		}
		else
		{		
			bullet.y = headSprite.getPosition().y + headSprite.getLocalBounds().height / 2;
		}
		bullet.x = headSprite.getPosition().x + headSprite.getLocalBounds().width / 2;
		bullet.timeShot = gameTime;
		bullet.direction = dir;
		bullet.speed = PLAYERS_BULLET_SPEED;
		bullet.damage = damage;
		lastShootPlayer = bullet.timeShot;
		bullets.push_back(bullet);
	}
	if (gameTime < lastShootPlayer + TIME_FOR_SHOOT_ANIMATION)
	{
		SetShootAnimation(dir);
	}
}

void Player::SetLastNotCollidedPosition()
{
	if (moving.x > 0)
	{
		position.x = playerOldPosition.x - 1;
	}
	else if (moving.x < 0)
	{
		position.x = playerOldPosition.x + 1;
	}
	if (moving.y > 0)
	{
		position.y = playerOldPosition.y - 1;
	}
	else if (moving.y < 0)
	{
		position.y = playerOldPosition.y + 1;
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

void Player::CheckEnemyCollidesPlayer(vector<Enemy>& enemies, float& gameTime, float& hitTimer, Sound& tearDestroy)
{
	for (auto& enemy: enemies)
	{
		if (enemy.alive == true)
		{
			if (IsIntersectsPlayerEnemy(enemy) && (gameTime > hitTimer + TIME_FOR_PLAYER_HIT_CD || hitTimer == 0))
			{
				health -= enemy.damage;
				hitTimer = gameTime;
				tearDestroy.play();
			}
			if (Collision::PixelPerfectTest(sprite, enemy.sprite))
			{
				if (enemy.name == "EnemyStandAndShoot")
				{
					canMove = false;
					SetLastNotCollidedPosition();
				}
			}
		}
	}
}

void Player::ChangeColorAfterHit(float& gameTime, float& hitTimer)
{
	if (gameTime < hitTimer + CHANGE_COLOR_EFFECT || gameTime < lastHitTime + CHANGE_COLOR_EFFECT && hitTimer != 0 || gameTime < bombHitTime + CHANGE_COLOR_EFFECT)
	{
		sprite.setColor(Color(COLOR_AFTER_HIT));
		headSprite.setColor(Color(COLOR_AFTER_HIT));
	}
	else
	{
		sprite.setColor(Color::White);
		headSprite.setColor(Color::White);
	}
}

void Player::CheckCollision(vector<Map> myMap, Sprite& wallSprite, View& view, bool areDoorsOpened)
{
	isSetSpeed = false;
	for (auto& map: myMap)
	{
		//if (Collision::PixelPerfectTest(sprite, map.sprite))
		if (GetSpriteRect(sprite).intersects(GetSpriteRect(map.sprite)))
		{
			if (map.pos == NOTDOOR)
			{
				FloatRect upRect = FloatRect(Vector2f(sprite.getPosition().x, sprite.getPosition().y - h), Vector2f(w, h));
				FloatRect rightRect = FloatRect(Vector2f(sprite.getPosition().x + w, sprite.getPosition().y), Vector2f(w, h));
				FloatRect downRect = FloatRect(Vector2f(sprite.getPosition().x, sprite.getPosition().y + h), Vector2f(w, h));
				FloatRect leftRect = FloatRect(Vector2f(sprite.getPosition().x - w, sprite.getPosition().y), Vector2f(w, h));
				if (moving.x > 0 && moving.y > 0)
				{
					if (downRect.intersects(map.sprite.getGlobalBounds()) && sprite.getPosition().x >= map.x - h)
					{
						position.x = position.x + speed;
						moving.x = 0;
					}
					else
					{
						position.y = position.y + speed;
						moving.y = 0;
					}
					isSetSpeed = true;
				}
				else if (moving.x > 0 && moving.y < 0)
				{
					if (upRect.intersects(map.sprite.getGlobalBounds()) && sprite.getPosition().x >= map.x - h)
					{
						position.x = position.x + speed;
						moving.x = 0;
					}
					else
					{
						position.y = position.y - speed;
						moving.y = 0;
					}
					isSetSpeed = true;
				}
				else if (moving.x < 0 && moving.y < 0)
				{
					if (upRect.intersects(map.sprite.getGlobalBounds()) && sprite.getPosition().y >= map.y + TILE_SIDE - h / 2)
					{
						position.x = position.x - speed;
						moving.x = 0;
					}
					else
					{
						position.y = position.y - speed;
						moving.y = 0;
					}
					isSetSpeed = true;
				}
				else if (moving.x < 0 && moving.y > 0)
				{
					cout << int(sprite.getPosition().x) << " " << int(map.x + TILE_SIDE) << endl;
					if (downRect.intersects(map.sprite.getGlobalBounds()) && int(sprite.getPosition().x) < int(map.x + TILE_SIDE - 1))
					{
						position.x = position.x - speed;
						moving.x = 0;
					}
					else
					{
						position.y = position.y + speed;
						moving.y = 0;
					}
					isSetSpeed = true;
				}
				else if (moving.x == 0 && moving.y > 0)
				{ 
					position.y = map.sprite.getPosition().y - h;
				}
				else if (moving.x == 0 && moving.y < 0)
				{ 
					position.y = map.sprite.getPosition().y + TILE_SIDE;
				}
				else if (moving.x > 0 && moving.y == 0)
				{ 
					position.x = map.sprite.getPosition().x - w;
				}
				else if (moving.x < 0 && moving.y == 0)
				{ 
					position.x = map.sprite.getPosition().x + TILE_SIDE;
				}
				break;
			}
			//if collides with door
			if (areDoorsOpened == true)
			{
				if (map.pos == RIGHT)
				{
					view.setCenter(view.getCenter().x + WINDOW_WIDTH, view.getCenter().y);
					position.x += TILE_SIDE * 4 + w;
					break;
				}
				else if (map.pos == LEFT)
				{
					view.setCenter(view.getCenter().x - WINDOW_WIDTH, view.getCenter().y);
					position.x -= TILE_SIDE * 4 + w;
					break;
				}
				else if (map.pos == UP)
				{
					view.setCenter(view.getCenter().x, view.getCenter().y - WINDOW_HEIGHT);
					position.y -= TILE_SIDE * 4 + h;
					break;
				}
				else if (map.pos == DOWN)
				{
					view.setCenter(view.getCenter().x, view.getCenter().y + WINDOW_HEIGHT);
					position.y += TILE_SIDE * 4 + h;
					break;
				}
			}
		}
		else if (Collision::PixelPerfectTest(sprite, wallSprite))
		{
			canMove = false;
			SetLastNotCollidedPosition();
			break;
		}
		else
		{
			playerOldPosition.x = position.x;
			playerOldPosition.y = position.y;
			canMove = true;
		}
	}
}

void Player::CheckExplosionCollision(Boomb& boomb, float& gameTime)
{
	FloatRect spriteRect = GetSpriteRect(sprite);
	FloatRect headSpriteRect = GetSpriteRect(headSprite);
	if (spriteRect.intersects(boomb.damageZone.getGlobalBounds()) || headSpriteRect.intersects(boomb.damageZone.getGlobalBounds()))
	{
		if (gameTime > bombHitTime + TIME_BEFORE_EXPLOSION && gameTime < boomb.explosionTime + 0.5)
		{
			health -= BOMB_DAMAGE;
			bombHitTime = gameTime;
		}
		if (gameTime > boomb.explosionTime + TIME_FOR_EXPLOSION / 2.f)
		{
			boomb.isAlive = false;
		}
	}
}

void Player::setSpeed()
{
		switch (dir)
		{
		case right: moving.x = speed; moving.y = 0; break;
		case left: moving.x = -speed; moving.y = 0; break;
		case down: moving.x = 0; moving.y = speed; break;
		case up: moving.x = 0; moving.y = -speed; break;
		case leftUp: moving.x = -speed*0.66f; moving.y = -speed*0.66f; break;
		case leftDown: moving.x = -speed*0.66f; moving.y = speed*0.66f; break;
		case rightUp: moving.x = speed*0.66f; moving.y = -speed*0.66f; break;
		case rightDown: moving.x = speed*0.66f; moving.y = speed*0.66f; break;
		case stay: moving.x = 0; moving.y = 0;
		}
}

void Player::Moving(float& time)
{
	if (canMove == true)
	{
		if (isSetSpeed == false)
		{
			setSpeed();
			position.x += moving.x * time;
			position.y += moving.y * time;
		}
	}

	sprite.setPosition(position.x, position.y);
	headSprite.setPosition(position.x - 14, position.y - 43);
}
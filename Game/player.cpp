#include "player.h"

#include "collision.h"


void Player::setFrame(float time)
{
	CurrentFrame += 0.005 * time;
	if (CurrentFrame > 4) CurrentFrame -= 4;
}

void Player::Control(vector<Bullet>& bullets, float time, float gameTime, float &lastShot)
{
	//move
	if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = leftUp;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = leftDown;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 60, 36, 26));
		headSprite.setTextureRect(IntRect(192, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = rightUp;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = rightDown;
		setFrame(time);
		sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 34, 36, 26));
		headSprite.setTextureRect(IntRect(64, 0, 32, 32));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
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

	//Shoot
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Shoot(bullets, gameTime, lastShot, 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Shoot(bullets, gameTime, lastShot, 5);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Shoot(bullets, gameTime, lastShot, 6);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Shoot(bullets, gameTime, lastShot, 7);
	}
}

//player shoots
void Player::Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir)
{
	if (gameTime > (lastShootPlayer + 0.5))
	{
		Bullet bullet;
		bullet.isPlayers = true;
		bullet.life = true;
		bullet.x = headSprite.getPosition().x + headSprite.getLocalBounds().width / 2;
		bullet.y = headSprite.getPosition().y + headSprite.getLocalBounds().height / 2;
		bullet.timeShot = gameTime;
		bullet.direction = dir;
		bullet.speed = 0.3;
		bullet.damage = damage;
		lastShootPlayer = bullet.timeShot;
		bullets.push_back(bullet);
	}
	if (gameTime < lastShootPlayer + 0.1)
	{
		headSprite.setTextureRect(IntRect(headSprite.getTextureRect().width + 32, 0, 32, 32));
	}
}

void Player::SetLastNotCollidedPosition()
{
	if (dx > 0)
	{
		x = playerOldPosition.x - 1;
	}
	else if (dx < 0)
	{
		x = playerOldPosition.x + 1;
	}
	if (dy > 0)
	{
		y = playerOldPosition.y - 1;
	}
	else if (dy < 0)
	{
		y = playerOldPosition.y + 1;
	}
}

void Player::CheckCollision(vector<Map> myMap, bool &canMove, Sprite& wallSprite, View& view)
{
	for (vector<Map>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		if (Collision::PixelPerfectTest(sprite, it->sprite))
		{
			//if collides with rock
			if (it->pos == NOTDOOR)
			{
				canMove = false;
				SetLastNotCollidedPosition();
				break;
			}
			//if collides with door
			else if (it->pos == RIGHT)
			{
				view.setCenter(view.getCenter().x + WINDOW_WIDTH, view.getCenter().y);
				x += TILE_SIDE * 4 + w;
				break;
			}
			else if (it->pos == LEFT)
			{
				view.setCenter(view.getCenter().x - WINDOW_WIDTH, view.getCenter().y);
				x -= TILE_SIDE * 4 + w;
				break;
			}
			else if (it->pos == UP)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y - WINDOW_HEIGHT);
				y -= TILE_SIDE * 4 + h;
				break;
			}
			else if (it->pos == DOWN)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y + WINDOW_HEIGHT);
				y += TILE_SIDE * 4 + h;
				break;
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
			playerOldPosition.x = x;
			playerOldPosition.y = y;
			canMove = true;
		}
	}
}

void Player::setSpeed()
{
	switch (dir)
	{
	case right: dx = speed; dy = 0; break;
	case left: dx = -speed; dy = 0; break;
	case down: dx = 0; dy = speed; break;
	case up: dx = 0; dy = -speed; break;
	case leftUp: dx = -speed*0.66; dy = -speed*0.66; break;
	case leftDown: dx = -speed*0.66; dy = speed*0.66; break;
	case rightUp: dx = speed*0.66; dy = -speed*0.66; break;
	case rightDown: dx = speed*0.66; dy = speed*0.66; break;
	case stay: dx = 0; dy = 0;
	}
}

void Player::Update(vector<Map> myMap, vector<Bullet>& bullets, float time, float gameTime, float &lastShootPlayer, Sprite & wallSprite, View & view)
{
	bool canMove = true;

	Control(bullets, time, gameTime, lastShootPlayer);
	CheckCollision(myMap, canMove, wallSprite, view);

	if (canMove == true)
	{
		setSpeed();
		x += dx * time;
		y += dy * time;
	}

	sprite.setPosition(x, y);
	headSprite.setPosition(x - 14, y - 43);
}
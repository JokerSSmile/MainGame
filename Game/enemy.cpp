#include "enemy.h"

#include "map.h"

void Enemy::CheckCollosionFly(vector<Map>& myMap, float& time)
{
	Vector2f oldPos = position;
	position.x += moving.x * time;
	position.y += moving.y * time;
	for (auto& map : myMap)
	{
		if (Collision::BoundingBoxTest(sprite, map.sprite) && map.pos != SPIKE)
		{
			if (moving.x > 0)
			{
				position.x = oldPos.x - 5;
			}
			else if (moving.x < 0)
			{
				position.x = oldPos.x + 5;
			}
			moving.x = -moving.x;
			moving.y = -moving.y;
			break;
		}
	}
}

void Enemy::Shoot(vector<Bullet>& bullets, float& gameTime, int& dir, float bulletStartX, float bulletStartY)
{
	Bullet bullet;
	bullet.isPlayers = false;
	bullet.alive = true;
	bullet.position.x = bulletStartX;
	bullet.position.y = bulletStartY;
	bullet.timeShot = gameTime;
	bullet.direction = dir;
	bullet.speed = ENEMY_BULLET_SPEED;
	bullet.damage = damage;
	bullet.startPos = position;
	bullet.isDel = false;
	bullet.bulletSprite.setScale(1.5, 1.5);
	lastShootEnemyStand = bullet.timeShot;
	bullets.push_back(bullet);
}

void Enemy::DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture, float& time, Sound& flyHurt, Sound& enemyHurt)
{
	poofSprite.setTexture(poofTexture);
	poofSprite.setScale(1.5, 1.5);
	poofSprite.setOrigin(TILE_SIDE / 2, TILE_SIDE / 2);
	poofSprite.setPosition(lastPosition.x + sprite.getGlobalBounds().width / 2, lastPosition.y + sprite.getGlobalBounds().height / 2);
	if (currentFrame == 0)
	{
		if (name == "EnemyFly")
		{
			flyHurt.play();
		}
		else
		{
			enemyHurt.play();
		}
	}
	if (gameTime > deathTime && gameTime < deathTime + ENEMY_DESTROY_EFFECT * 4)
	{
		if (currentFrame < EXPLOSION_FRAMES_COUNT)
		{
			currentFrame += FRAME_CHANGE_TIME_EXPLOSION * time;
		}
		poofSprite.setTextureRect(IntRect(EXPLOSION_TEXTURE_IMAGE_SIZE * (int(currentFrame) % EXPLOSION_FRAME_COUNT), EXPLOSION_TEXTURE_IMAGE_SIZE * (int(currentFrame) / EXPLOSION_FRAME_COUNT), EXPLOSION_TEXTURE_IMAGE_SIZE, EXPLOSION_TEXTURE_IMAGE_SIZE));
		window.draw(poofSprite);
	}
}

bool Enemy::isIntersectEnemy(vector<Enemy>& enemies)
{
	for (auto& enemy : enemies)
	{
		if (enemy.sprite.getPosition() != sprite.getPosition() && (enemy.name == "EnemyFollow" || enemy.name == "Worm") && enemy.health > 0)
		{
			if (Collision::BoundingBoxTest(sprite, enemy.sprite) && sprite.getPosition().x != 0)
			{
				return true;
			}
		}
	}
	return false;
}

void Enemy::ExplosionCollision(Boomb& boomb, float& gameTime)
{
	if (sprite.getGlobalBounds().intersects(boomb.damageZone.getGlobalBounds()))
	{
		if (gameTime > bombHitTime + TIME_BEFORE_EXPLOSION && gameTime < boomb.explosionTime + FRAME_CHANGE_TIME)
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

void Enemy::ChangeColorAfterHit(float& gameTime, Boomb& boomb)
{
	if (gameTime < playerHitTime + CHANGE_COLOR_EFFECT || (gameTime > bombHitTime && gameTime < bombHitTime + FRAME_CHANGE_TIME))
	{
		sprite.setColor(COLOR_AFTER_HIT);
		headSprite.setColor(COLOR_AFTER_HIT);
	}
	else
	{
		sprite.setColor(Color::White);
		headSprite.setColor(Color::White);
	}
}

void Enemy::UpdateFly(float& time, vector<Map>& myMap)
{
	if (name == "EnemyFly")
	{
		currentFrame += FLY_UPDATE_FRAME_TIME * time;
		if (currentFrame > 2)
		{
			currentFrame -= 2;
		}
		sprite.setTextureRect(IntRect(FLY_SIZE.x * int(currentFrame), 0, FLY_SIZE.x, FLY_SIZE.y));
		CheckCollosionFly(myMap, time);
		sprite.setPosition(position.x, position.y);
	}
}

void Enemy::UpdateStandAndShoot(vector<Bullet>& bullets, float& gameTime)
{
	if (name == "EnemyStandAndShoot")
	{
		enemyTime = clock.getElapsedTime().asSeconds();
		if (enemyTime > (TIME_BETWEEN_SHOOT_ENEMY_STAND))
		{
			for (int i = 4; i <= 7; i++)
			{
				Shoot(bullets, gameTime, i, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 16, sprite.getPosition().y + 32);
			}
			clock.restart();
		}
		sprite.setScale(2, 2);
		sprite.setPosition(position);
		if (lastShootEnemyStand + ENEMY_STAND_AND_SHOOT_FRAME_TIME <= gameTime && lastShootEnemyStand != 0)
		{
			sprite.setTextureRect(IntRect(0, 0, STAND_AND_SHOOT_SIZE.x, STAND_AND_SHOOT_SIZE.y));
		}
		else
		{
			sprite.setTextureRect(IntRect(STAND_AND_SHOOT_SIZE.x, 0, STAND_AND_SHOOT_SIZE.x, STAND_AND_SHOOT_SIZE.y));
		}
	}
}

void Enemy::SetWarmDir()
{
	int randNum = int(RandomNumber(4, 4));
	switch (randNum)
	{
	case 4: dir = LEFT;
		break;
	case 5: dir = UP;
		break;
	case 6: dir = DOWN;
		break;
	case 7: dir = RIGHT;
		break;
	default:
		break;
	}
	clock.restart();
}

void Enemy::UpdateFrameWorm(float& time)
{
	currentFrame += 0.006f * time;
	if (currentFrame > 4) currentFrame -= 4;
	switch (dir)
	{
	case 4:
		if (followState == FAR)
		{
			sprite.setTextureRect(IntRect(64 * int(currentFrame), 256, 64, 64));
		}
		else
		{
			sprite.setTextureRect(IntRect(128, 192, 64, 64));
		}
		break;
	case 7: 
		if (followState == FAR)
		{
			sprite.setTextureRect(IntRect(64 * int(currentFrame), 0, 64, 64));
		}
		else
		{
			sprite.setTextureRect(IntRect(64, 192, 64, 64));
		}
		break;
	case 5: 
		if (followState == FAR)
		{
			sprite.setTextureRect(IntRect(64 * int(currentFrame), 64, 64, 64));
		}
		else
		{
			sprite.setTextureRect(IntRect(192, 192, 64, 64));
		}
		break;
	case 6: 
		if (followState == FAR)
		{
			sprite.setTextureRect(IntRect(64 * int(currentFrame), 128, 64, 64));
		}
		else
		{
			sprite.setTextureRect(IntRect(0, 192, 64, 64));
		}
		break;
	default: sprite.setTextureRect(IntRect(0, 0, 64, 64));
		break;
	}
}

void Enemy::SetWormSpeed()
{
	switch (followState)
	{
	case FAR: speed = ENEMY_FOLLOW_SPEED_NORMAL;
		break;
	case NEAR: speed = WORM_FOLLOW_SPEED;
		break;
	default:
		break;
	}
}

void Enemy::UpdateWorm(vector<Map>& myMap, vector<Enemy>& enemies, float& gameTime, float& time)
{
	if (name == "Worm")
	{
 		UpdateFrameWorm(time);
		if ((enemyTime > 2 && followState == FAR) )
		{
			SetWarmDir();
		}
		Vector2f(oldPosition) = sprite.getPosition();
		SetWormSpeed();
		SetPosition(time, speed);
		sprite.setPosition(position);
		if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
		{
			SetWarmDir();
			followState = FAR;
			sprite.setPosition(oldPosition);
			if (position.x != oldPosition.x && position.y != oldPosition.y)
			{
				sprite.setPosition(oldPosition.x, position.y);
				if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
				{
					sprite.setPosition(position.x, oldPosition.y);
					if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
					{
						sprite.setPosition(oldPosition);
					}
				}
			}
			enemyTime = 3;
			isStacked = true;
		}
		else
		{
			enemyTime = clock.getElapsedTime().asSeconds();
			isStacked = false;
		}
		position = sprite.getPosition();
		spriteCenterPos.x = position.x + size.x / 2;
		spriteCenterPos.y = position.y + size.y / 2;
	}
}

void Enemy::UpdateStrightDir(Vector2f& playerPosition, bool& isStrightDir)
{
	float shift = 20;
	if (spriteCenterPos.x >= playerPosition.x - shift && spriteCenterPos.x <= playerPosition.x + PLAYER_SIZE.x + shift)
	{
		if (spriteCenterPos.y >= playerPosition.y)
		{			
			if (name == "EnemyFollow")
			{
				dir = UP;
			}
			else
			{
				if (dir == UP && isStacked == false)
				{
					followState = NEAR;
				}
			}
		}
		else
		{			
			if (name == "EnemyFollow")
			{
				dir = DOWN;
			}
			else
			{
				if (dir == DOWN && isStacked == false)
				{
					followState = NEAR;
				}
			}
		}
		isStrightDir = true;
	}
	else if (spriteCenterPos.y >= playerPosition.y - shift && spriteCenterPos.y <= playerPosition.y + PLAYER_SIZE.y + shift)
	{
		if (spriteCenterPos.x >= playerPosition.x)
		{			
			if (name == "EnemyFollow")
			{
				dir = LEFT;
			}
			else
			{
				if (dir == LEFT && isStacked == false)
				{
					followState = NEAR;
				}
			}
		}
		else
		{
			if (name == "EnemyFollow")
			{
				dir = RIGHT;
			}
			else
			{
				if (dir == RIGHT && isStacked == false)
				{
					followState = NEAR;
				}
			}
		}
		isStrightDir = true;
	}
	else
	{
		if (name == "Worm")
		{
			followState = FAR;
		}
	}
}

void Enemy::SetDirection(Vector2f& playerPosition)
{
	if (name == "Worm" || name == "EnemyFollow")
	{
		float shift = 20;
		bool isStrightDir = false;
		UpdateStrightDir(playerPosition, isStrightDir);
		if (isStrightDir == false && name == "EnemyFollow")
		{
			if (spriteCenterPos.x > playerPosition.x + PLAYER_SIZE.x + shift && spriteCenterPos.y < playerPosition.y)
			{
				dir = LEFT_DOWN;
			}
			else if (spriteCenterPos.x > playerPosition.x + PLAYER_SIZE.x + shift && spriteCenterPos.y > playerPosition.y + PLAYER_SIZE.y + shift)
			{
				dir = LEFT_UP;
			}
			else if (spriteCenterPos.x < playerPosition.x - shift && spriteCenterPos.y < playerPosition.y)
			{
				dir = RIGHT_DOWN;
			}
			else if (spriteCenterPos.x < playerPosition.x - shift && spriteCenterPos.y > playerPosition.y + PLAYER_SIZE.y + shift)
			{
				dir = RIGHT_UP;
			}
		}
	}
}

void Enemy::UpdateHeadFrame(Texture& followHeadTexture, float& gameTime)
{
	headSprite.setTexture(followHeadTexture);
	switch (followState)
	{
	case FAR:
	{
		headSprite.setTextureRect(IntRect(64, 0, 64, 64));
		headSprite.setPosition(sprite.getPosition().x - SHIFT_FOR_HEAD.x, sprite.getPosition().y - SHIFT_FOR_HEAD.y - 5);
		break;
	}
	case NEAR:
	{
		headSprite.setTextureRect(IntRect(64, 64, 64, 64));
		headSprite.setPosition(sprite.getPosition().x - SHIFT_FOR_HEAD.x, sprite.getPosition().y - SHIFT_FOR_HEAD.y - 10);
		break;
	}
	default:
		break;
	}
}

void Enemy::SetFrameFollowEnemy(float& time, Vector2f& playerPosition)
{
	if (position.x >= playerPosition.x)
	{
		currentFrame += 0.005f * time;
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite.setTextureRect(IntRect(36 * int(currentFrame), 60, 36, 26));

	}
	else
	{
		currentFrame += 0.005f * time;
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite.setTextureRect(IntRect(36 * int(currentFrame), 34, 36, 26));
	}
}

bool Enemy::IsIntersectsMap(vector<Map>& myMap)
{
	for (auto& map : myMap)
	{
		if (Collision::BoundingBoxTest(sprite, map.sprite) && (map.pos == ROCK || map.pos == WALL))
		{
			return true;
		}
	}
	return false;
}

void Enemy::UpdateState(Vector2f& playerPosition)
{
	float x1 = position.x;
	float x2 = playerPosition.x;
	float y1 = position.y;
	float y2 = playerPosition.y;
	if (sqrt(pow((x2 - x1), 2) + (pow((y2 - y1), 2))) > 200)
	{
		followState = FAR;
		speed = ENEMY_FOLLOW_SPEED_NORMAL;
	}
	else
	{
		followState = NEAR;
		speed = ENEMY_FOLLOW_SPEED_FAST;
	}
}

void Enemy::MoveFollowEnemy(float& gameTime, Vector2f& playerPosition, vector<Map>& myMap, float& time, vector<Enemy>& enemies)
{
	if (name == "EnemyFollow")
	{
		UpdateState(playerPosition);
		SetFrameFollowEnemy(time, playerPosition);
		Vector2f(oldPosition) = sprite.getPosition();
		SetPosition(time, speed);
		sprite.setPosition(position);
		if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
		{
			sprite.setPosition(oldPosition);
			if (position.x != oldPosition.x && position.y != oldPosition.y)
			{
				sprite.setPosition(oldPosition.x, position.y);
				if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
				{
					sprite.setPosition(position.x, oldPosition.y);
					if (IsIntersectsMap(myMap) == true || isIntersectEnemy(enemies) == true)
					{
						sprite.setPosition(oldPosition);
					}
				}
			}
		}
		position = sprite.getPosition();
		spriteCenterPos.x = position.x + size.x / 2;
		spriteCenterPos.y = position.y + size.y / 2;
	}
}

void Enemy::isNeedRemove(float& gameTime)
{
	if (gameTime > deathTime + 2)
	{
		isRemove = true;
	}
	isRemove = false;
}

void Enemy::CheckIsAlive(float& gameTime)
{
	if (health > 0)
	{
		alive = true;
	}
	else
	{
		currentFrame = 0;
		alive = false;
		sprite.setPosition(WINDOW_WIDTH * 3, WINDOW_HEIGHT* 3);
	}
}

void Enemy::Update(Boomb& boomb, float& gameTime, Vector2f& playerPosition)
{
	SetDirection(playerPosition);
	isNeedRemove(gameTime);
	ChangeColorAfterHit(gameTime, boomb);
	CheckIsAlive(gameTime);
	lastPosition = position;
}
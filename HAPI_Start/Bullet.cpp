#include "Bullet.h"
#include "World.h"

void Bullet::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec, int& Score, int& PlayerTickDamage, std::string Difficulty)
{
	if (Alive)
	{
		//kills sprite if health is 0 or less.
		if (Health <= 0)
			Alive = false;
	}

	//Animations
	switch (YDirection)
	{
	case 1:
		switch (Tick)
		{
		case 0:
			E_SpriteName = "BulletSpriteDown1";
			break;
		case 1:
			E_SpriteName = "BulletSpriteDown2";
			break;
		case 2:
			E_SpriteName = "BulletSpriteDown3";
			break;
		}
		break;
	case 2:
		switch (Tick)
		{
		case 0:
			E_SpriteName = "BulletSpriteUp1";
			break;
		case 1:
			E_SpriteName = "BulletSpriteUp2";
			break;
		case 2:
			E_SpriteName = "BulletSpriteUp3";
			break;
		}
		break;
	default:
		switch (XDirection)
		{
		case 0:
			switch (Tick)
			{
			case 0:
				E_SpriteName = "BulletSpriteRight1";
				break;
			case 1:
				E_SpriteName = "BulletSpriteRight2";
				break;
			case 2:
				E_SpriteName = "BulletSpriteRight3";
				break;
			}
			break;
		case 1:
			switch (Tick)
			{
			case 0:
				E_SpriteName = "BulletSpriteLeft1";
				break;
			case 1:
				E_SpriteName = "BulletSpriteLeft2";
				break;
			case 2:
				E_SpriteName = "BulletSpriteLeft3";
				break;
			}
			break;
		}
		break;
	}


	if (Alive)
	{
		RenderSprite(Rend);

		//movement
		switch (YDirection)
		{
		case 1:
			YPos += 10;
			break;
		case 2:
			YPos -= 10;
			break;
		default:
			switch (XDirection)
			{
			case 0:
				XPos += 10;
				break;
			case 1:
				XPos -= 10;
				break;
			}
			break;
		}

		if (Tick < 3)
		{
			Tick++;
		}
		else
		{
			Tick = 0;
		}

		//killes if goes off screen
		if (YPos < -10 || YPos > Rend.ScreenHeight() + 10 || XPos < -10 || XPos > Rend.ScreenWidth() + 10)
		{
			Alive = false;
		}
	}
}

Sides Bullet::GetSide()
{
	//sets side of sprite
	return Sides::EPlayer;
}

void Bullet::Setup()
{
	//sets sprite to not be alive.
	Alive = false;
}



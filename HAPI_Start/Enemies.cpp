#include "Enemies.h"


void Enemies::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Health <= 0)
		Alive = false;

	if (Alive)
	{
		switch (YDirection)
		{
		case 1:
			switch (Tick)
			{
			case 0:
				E_SpriteName = "EnemiesSpriteDown1";
				break;
			case 1:
				E_SpriteName = "EnemiesSpriteDown2";
				break;
			case 2:
				E_SpriteName = "EnemiesSpriteDown3";
				break;
			case 3:
				E_SpriteName = "EnemiesSpriteDown2";
				break;
			}
			break;
		case 2:
			switch (Tick)
			{
			case 0:
				E_SpriteName = "EnemiesSpriteUp1";
				break;
			case 1:
				E_SpriteName = "EnemiesSpriteUp2";
				break;
			case 2:
				E_SpriteName = "EnemiesSpriteUp3";
				break;
			case 3:
				E_SpriteName = "EnemiesSpriteUp2";
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
					E_SpriteName = "EnemiesSpriteRight1";
					break;
				case 1:
					E_SpriteName = "EnemiesSpriteRight2";
					break;
				case 2:
					E_SpriteName = "EnemiesSpriteRight3";
					break;
				case 3:
					E_SpriteName = "EnemiesSpriteRight2";
					break;
				}
				break;
			case 1:
				switch (Tick)
				{
				case 0:
					E_SpriteName = "EnemiesSpriteLeft1";
					break;
				case 1:
					E_SpriteName = "EnemiesSpriteLeft2";
					break;
				case 2:
					E_SpriteName = "EnemiesSpriteLeft3";
					break;
				case 3:
					E_SpriteName = "EnemiesSpriteLeft2";
					break;
				}
				break;
			}
			break;
		}
		

		RenderSprite(Rend);


		switch (YDirection)
		{
		case 1:
			if (Count == 50)
			{
				YPos +=  10;
				Count = 0;
				if (Tick < 3)
				{
					Tick++;
				}
				else
				{
					Tick = 0;
				}
			}
			Count++;
			break;
		case 2:
			if (Count == 50)
			{
				YPos -= 10;
				Count = 0;
				if (Tick < 3)
				{
					Tick++;
				}
				else
				{
					Tick = 0;
				}
			}
			Count++;
			break;
		default:
			switch (XDirection)
			{
			case 0:
				if (Count == 50)
				{
					XPos += 10;
					Count = 0;
					if (Tick < 3)
					{
						Tick++;
					}
					else
					{
						Tick = 0;
					}
				}
				Count++;
				break;
			case 1:
				if (Count == 50)
				{
					XPos -= 10;
					Count = 0;
					if (Tick < 3)
					{
						Tick++;
					}
					else
					{
						Tick = 0;
					}
				}
				Count++;
				break;
			}
			break;
		}
	}
}

Sides Enemies::GetSide()
{
	return Sides::EEnemy;
}

void Enemies::Setup()
{
	Alive = true;

	Health = 25;

	//srand(time(NULL));

	YDirection = rand() % 2;
	if (YDirection == 0)
	{
		XDirection = rand() % 1;
	}

	switch (YDirection)
	{
	case 1:
		XPos = rand() % 424 + 250;
		YPos = -5;
		break;
	case 2:
		XPos = rand() % 424 + 250;
		YPos = 770;
		break;
	default:
		switch (XDirection)
		{
		case 0:
			XPos = -5;
			YPos = rand() % 418 + 225;
			break;
		case 1:
			XPos = 1030;
			YPos = rand() % 418 + 225;
			break;
		}
		break;
	}
}

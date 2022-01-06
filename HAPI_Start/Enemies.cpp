#include "Enemies.h"


void Enemies::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec, int& Score, int& PlayerTickDamage, std::string Difficulty)
{
	if (Alive)
	{
		//kills sprite if health is 0 or less.
		if (Health <= 0)
		{
			Alive = false;
			Score += 10;
		}
	}

	if (Alive)
	{
		//Animations
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
		case 4:
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
		case 5:
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
		case 7:
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
		case 8:
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
			case 2:
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
			case 3:
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
			case 4:
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
			case 5:
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

		//Movement
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
				if (YPos >= 695)
				{
					Setup();
					PlayerTickDamage++;
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
				if (YPos <= -15)
				{
					Setup();
					PlayerTickDamage++;
				}
			}
			Count++;
			break;
		case 4:
			if (Count == 50)
			{
				YPos += 10;
				Count = 0;
				if (Tick < 3)
				{
					Tick++;
				}
				else
				{
					Tick = 0;
				}
				if (YPos >= 695)
				{
					Setup();
					PlayerTickDamage++;
				}
			}
			Count++;
			break;
		case 5:
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
				if (YPos <= -15)
				{
					Setup();
					PlayerTickDamage++;
				}
			}
			Count++;
			break;
		case 7:
			if (Count == 50)
			{
				YPos += 10;
				Count = 0;
				if (Tick < 3)
				{
					Tick++;
				}
				else
				{
					Tick = 0;
				}
				if (YPos >= 695)
				{
					Setup();
					PlayerTickDamage++;
				}
			}
			Count++;
			break;
		case 8:
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
				if (YPos <= -15)
				{
					Setup();
					PlayerTickDamage++;
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
					if (XPos >= 1030)
					{
						Setup();
						PlayerTickDamage++;
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
					if (XPos <= -15)
					{
						Setup();
						PlayerTickDamage++;
					}
				}
				Count++;
				break;
			case 2:
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
					if (XPos >= 1030)
					{
						Setup();
						PlayerTickDamage++;
					}
				}
				Count++;
				break;
			case 3:
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
					if (XPos <= -15)
					{
						Setup();
						PlayerTickDamage++;
					}
				}
				Count++;
				break;
			case 4:
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
					if (XPos >= 1030)
					{
						Setup();
						PlayerTickDamage++;
					}
				}
				Count++;
				break;
			case 5:
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
					if (XPos <= -15)
					{
						Setup();
						PlayerTickDamage++;
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
	//set what side it is on.
	return Sides::EEnemy;
}

void Enemies::Setup()
{
	//sets up the sprite with health and positions
	Alive = true;

	Health = 25;

	YDirection = rand() % 8;
	XDirection = rand() % 5;

	switch (YDirection)
	{
	case 1:
		XPos = rand() % 424 + 250;
		YPos = -15;
		break;
	case 2:
		XPos = rand() % 424 + 250;
		YPos = 690;
		break;
	case 4:
		XPos = rand() % 424 + 250;
		YPos = -15;
		break;
	case 5:
		XPos = rand() % 424 + 250;
		YPos = 690;
		break;
	case 7:
		XPos = rand() % 424 + 250;
		YPos = -15;
		break;
	case 8:
		XPos = rand() % 424 + 250;
		YPos = 690;
		break;
	default:
		switch (XDirection)
		{
		case 0:
			XPos = -15;
			YPos = rand() % 418 + 225;
			break;
		case 1:
			XPos = 1030;
			YPos = rand() % 418 + 225;
			break;
		case 2:
			XPos = -15;
			YPos = rand() % 418 + 225;
			break;
		case 3:
			XPos = 1030;
			YPos = rand() % 418 + 225;
			break;
		case 4:
			XPos = -15;
			YPos = rand() % 418 + 225;
			break;
		case 5:
			XPos = 1030;
			YPos = rand() % 418 + 225;
			break;
		}
		break;
	}
}

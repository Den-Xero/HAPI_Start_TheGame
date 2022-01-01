#include "Player.h"
#include "Controls.h"
#include "World.h"

void Player::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Health <= 0)
		Alive = false;
	switch (XDirection)
	{
	case 0:
		switch (Tick)
		{
		case 0:
			E_SpriteName = "PlayerSpriteRight1";
			break;
		case 1:
			E_SpriteName = "PlayerSpriteRight2";
			break;
		case 2:
			E_SpriteName = "PlayerSpriteRight3";
			break;
		}
		break;
	case 1:
		switch (Tick)
		{
		case 0:
			E_SpriteName = "PlayerSpriteLeft1";
			break;
		case 1:
			E_SpriteName = "PlayerSpriteLeft2";
			break;
		case 2:
			E_SpriteName = "PlayerSpriteLeft3";
			break;
		}
		break;
	default:
		break;
	}

	if (Alive)
	{
		ControllarData = P_Con.SetData();
		//controller, rumble and keybord controls calls.
		if (ControllarData.isAttached)
		{
			P_Con.XboxControls(XPos, YPos, XDirection, YDirection, Tick);

			P_Con.Rumble(Health);

			if (P_Con.fireXbox())
			{
				for (size_t i = BulletStart; i <= BulletEnd; i++)
				{
					if (!Vec[i]->IsAlive())
					{
						Vec[i]->SetAlive();

						Vec[i]->SetPositions(XPos, YPos, XDirection, YDirection);

						Vec[i]->UpdateLoop(Rend, BulletStart, BulletEnd, Vec);

						break;
					}
				}
			}
		}
		else
		{
			P_Con.KeyboardControls(XPos, YPos, XDirection, YDirection, Tick);

			if (P_Con.fireKeyboard())
			{
				for (size_t i = BulletStart; i <= BulletEnd; i++)
				{
					if (!Vec[i]->IsAlive())
					{
						Vec[i]->SetAlive();

						Vec[i]->SetPositions(XPos, YPos, XDirection, YDirection);

						Vec[i]->UpdateLoop(Rend, BulletStart, BulletEnd, Vec);

						break;
					}
				}
			}
		}

		RenderSprite(Rend);
	}
}

Sides Player::GetSide()
{
	return Sides::EPlayer;
}

void Player::Setup()
{
	Alive = true;

	Health = 100;

	P_Con.GetValues();

	XPos = 100;
	YPos = 200;
}


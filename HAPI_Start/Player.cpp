#include "Player.h"
#include "Controls.h"
#include "World.h"

void Player::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec, int& Score, int& PlayerTickDamage, std::string Difficulty)
{
	if (PlayerTickDamage > 0)
	{
		if (Difficulty == "E")
		{
			//takes health off player after enemies go off screen.
			Health -= PlayerTickDamage;
			PlayerTickDamage = 0;
		}
		else if (Difficulty == "M")
		{
			//takes health off player after enemies go off screen.
			PlayerTickDamage *= 2;
			Health -= PlayerTickDamage;
			PlayerTickDamage = 0;
		}
		else if (Difficulty == "H")
		{
			//takes health off player after enemies go off screen.
			PlayerTickDamage *= 4;
			Health -= PlayerTickDamage;
			PlayerTickDamage = 0;
		}
		
	}

	//puts players health on screen
	std::string PlayerScore = "Your score is: " + std::to_string(Health);
	HAPI.RenderText(0, 40, HAPI_TColour::RED, PlayerScore, 20, eBold);

	if (Health <= 0)
	{
		//kills sprite if health is 0 or less and ask user if they want to restart.
		Alive = false;
		HAPI.UserMessage("You are dead, Your score is: " + std::to_string(Score) + ". Would you like to restart?", "Game over", HAPI_ButtonType::eButtonTypeYesNo, &Response);
		if (Response == HAPI_UserResponse::eUserResponseYes)
		{
			World World;
			World.SetRestarted();
			World.Run(Rend);
		}
		else
		{
			HAPI.Close();
		}
	}
		
	//Animations
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
		//movement and shooting.
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

						Vec[i]->UpdateLoop(Rend, BulletStart, BulletEnd, Vec, Score, PlayerTickDamage, Difficulty);

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

						Vec[i]->UpdateLoop(Rend, BulletStart, BulletEnd, Vec, Score, PlayerTickDamage, Difficulty);

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
	//sets what side the sprite is on.
	return Sides::EPlayer;
}

void Player::Setup()
{
	//sets up the sprite with health and positions
	Alive = true;

	Health = 100;

	P_Con.GetValues();

	XPos = 512;
	YPos = 342;
}


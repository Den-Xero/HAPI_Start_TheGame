#include "Player.h"
#include "Controls.h"
#include "World.h"

void Player::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Alive)
	{
		ControllarData = P_Con.SetData();
		//controller, rumble and keybord controls calls.
		if (ControllarData.isAttached)
		{
			P_Con.XboxControls(XPos, YPos);

			P_Con.Rumble(Health);

			if (P_Con.fireXbox())
			{

			}
		}
		else
		{
			P_Con.KeyboardControls(XPos, YPos);

			if (P_Con.fireKeyboard())
			{

				for (size_t i = BulletStart; i <= BulletEnd; i++)
				{
					if (!Vec[i]->IsAlive())
					{
						Vec[i]->SetAlive();

						Vec[i]->SetPositions(XPos, YPos);

						Vec[i]->RenderSprite(Rend);

						break;
					}
				}
			}
		}

		RenderSprite(Rend);
	}
}

void Player::Setup()
{
	Alive = true;

	Health = 100;

	P_Con.GetValues();

	XPos = 100;
	YPos = 200;
}


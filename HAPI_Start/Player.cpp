#include "Player.h"
#include "Controls.h"

void Player::UpdateLoop(Render &Rend)
{
	ControllarData = P_Con.SetData();
	//controller, rumble and keybord controls calls.
	if (ControllarData.isAttached)
	{
		P_Con.XboxControls(XPos, YPos);

		P_Con.Rumble(XPos, YPos);
	}
	else
	{
		P_Con.KeyboardControls(XPos, YPos);
	}

	RenderSprite(Rend);
}

void Player::Setup()
{
	P_Con.GetValues();

	XPos = 100;
	YPos = 200;
}

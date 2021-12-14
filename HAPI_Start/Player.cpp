#include "Player.h"
#include "Controls.h"

void Player::UpdateLoop(Render &Rend)
{
	ControllarData = P_Con.SetData();
	//controller, rumble and keybord controls calls.
	if (ControllarData.isAttached)
	{
		P_Con.XboxControls(Pos.X, Pos.Y);

		P_Con.Rumble(Pos.X, Pos.Y);
	}
	else
	{
		P_Con.KeyboardControls(Pos.X, Pos.Y);
	}

	RenderSprite(Rend);
}

void Player::RenderSprite(Render &Rend)
{
	Rend.PlayerSpriteRender(E_SpriteName, Pos.X, Pos.Y);

}

void Player::Setup()
{
	P_Con.GetValues();

	Pos = { 100, 200 };
}

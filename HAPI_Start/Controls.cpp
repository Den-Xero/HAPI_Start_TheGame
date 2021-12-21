#include "Controls.h"
#include "Render.h"
#include "Sprite.h"
#include "Bullet.h"

void Controls::GetValues()
{
	//getter
	Render Rend;
	PassedScreenHeight = Rend.ScreenHeight();
	PassedScreenWidth = Rend.ScreenWidth();
}

HAPI_TControllerData Controls::SetData()
{
	const HAPI_TControllerData& ControllarKeybinds = HAPI.GetControllerData(0);
	return ControllarKeybinds;
}

bool Controls::fireKeyboard()
{
	if (KeyboardKeybinds.scanCode[HK_SPACE])
	{
		return true;
	}
	return false;
}

bool Controls::fireXbox()
{
	//Gets the controller data.
	const HAPI_TControllerData& ControllarKeybinds = HAPI.GetControllerData(0);
	if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
	{
		return true;
	}
	return false;
}

void Controls::KeyboardControls(float &XPos, float &YPos)
{
	//checks the keyboard data to move the sptite.
	 if (KeyboardKeybinds.scanCode['A'] && KeyboardKeybinds.scanCode['S'])
	 {
		 XPos -= MagSpeed;
		 YPos += MagSpeed;
	 }
	else if (KeyboardKeybinds.scanCode['A'] && KeyboardKeybinds.scanCode['W'])
	 {
		XPos -= MagSpeed;
		YPos -= MagSpeed;
	 }
	else if (KeyboardKeybinds.scanCode['D'] && KeyboardKeybinds.scanCode['S'])
	 {
		XPos += MagSpeed;
		YPos += MagSpeed;
	 }
	else if (KeyboardKeybinds.scanCode['D'] && KeyboardKeybinds.scanCode['W'])
	 {
		XPos += MagSpeed;
		YPos -= MagSpeed;
	 }
	else if (KeyboardKeybinds.scanCode['W'])
	 {
		YPos -= Speed;
	 }
	else if (KeyboardKeybinds.scanCode['S'])
	 {
		YPos += Speed;
	 }
	else if (KeyboardKeybinds.scanCode['D'])
	 {
		XPos += Speed;
	 }
	 else if (KeyboardKeybinds.scanCode['A'])
	 {
		 XPos -= Speed;
	 }
}

void Controls::XboxControls(float& XPos, float& YPos)
{
	//Gets the controller data.
	const HAPI_TControllerData& ControllarKeybinds = HAPI.GetControllerData(0);
	//checks the controller data to move the sptite.
	if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= MagSpeed;
		YPos += MagSpeed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= MagSpeed;
		YPos -= MagSpeed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += MagSpeed;
		YPos += MagSpeed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += MagSpeed;
		YPos -= MagSpeed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		YPos -= Speed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		YPos += Speed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += Speed;
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= Speed;
	}
}

void Controls::Rumble(int Health)
{
	//sets rumble to 0
	HAPI.SetControllerRumble(0, 0, 0);
	//sees if sprite is dead.
	if (Health <= 0)
	{
		HAPI.SetControllerRumble(0, 65535, 65535);
	}
}



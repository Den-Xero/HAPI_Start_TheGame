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
	if (Count == 0)
	{
		if (KeyboardKeybinds.scanCode['F'])
		{
			Count++;
			return true;
		}
	}
	else
	{
		if (Count == 5)
		{
			Count = 0;
		}
		else
		{
			Count++;
		}
		return false;
	}
}

bool Controls::fireXbox()
{
	if (Count == 0)
	{
		//Gets the controller data.
		const HAPI_TControllerData& ControllarKeybinds = HAPI.GetControllerData(0);
		if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
		{
			return true;
		}
	}
	else
	{
		if (Count == 10)
		{
			Count = 0;
		}
		else
		{
			Count++;
		}

		return false;
	}
	
}

void Controls::KeyboardControls(float &XPos, float &YPos, int& XDirection, int& YDirection, int& Tick)
{
	//checks the keyboard data to move the sptite.
	 if (KeyboardKeybinds.scanCode['A'] && KeyboardKeybinds.scanCode['S'])
	 {
		 XPos -= MagSpeed;
		 YPos += MagSpeed;
		 switch (XDirection)
		 {
		 case 1:
			 YDirection = 1;
			 if (Tick < 3)
			 {
				 Tick++;
			 }
			 else
			 {
				 Tick = 1;
			 }
			 break;
		 default:
			 XDirection = 1;
			 YDirection = 1;
			 Tick = 0;
			 break;
		 }
		 
	 }
	else if (KeyboardKeybinds.scanCode['A'] && KeyboardKeybinds.scanCode['W'])
	 {
		XPos -= MagSpeed;
		YPos -= MagSpeed;
		switch (XDirection)
		{
		case 1:
			YDirection = 2;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 1;
			YDirection = 2;
			Tick = 0;
			break;
		}
	 }
	else if (KeyboardKeybinds.scanCode['D'] && KeyboardKeybinds.scanCode['S'])
	 {
		XPos += MagSpeed;
		YPos += MagSpeed;
		switch (XDirection)
		{
		case 0:
			YDirection = 1;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 1;
			Tick = 0;
			break;
		}
	 }
	else if (KeyboardKeybinds.scanCode['D'] && KeyboardKeybinds.scanCode['W'])
	 {
		XPos += MagSpeed;
		YPos -= MagSpeed;
		switch (XDirection)
		{
		case 0:
			YDirection = 2;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 2;
			Tick = 0;
			break;
		}
	 }
	else if (KeyboardKeybinds.scanCode['W'])
	 {
		YPos -= Speed;
		YDirection = 2;
		if (Tick < 3)
		{
			Tick++;
		}
		else
		{
			Tick = 1;
		}
	 }
	else if (KeyboardKeybinds.scanCode['S'])
	 {
		YPos += Speed;
		YDirection = 1;
		if (Tick < 3)
		{
			Tick++;
		}
		else
		{
			Tick = 1;
		}
	 }
	else if (KeyboardKeybinds.scanCode['D'])
	 {
		XPos += Speed;
		switch (XDirection)
		{
		case 0:
			YDirection = 0;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 0;
			Tick = 0;
			break;
		}
	 }
	 else if (KeyboardKeybinds.scanCode['A'])
	 {
		 XPos -= Speed;
		 switch (XDirection)
		 {
		 case 1:
			 YDirection = 0;
			 if (Tick < 3)
			 {
				 Tick++;
			 }
			 else
			 {
				 Tick = 1;
			 }
			 break;
		 default:
			 XDirection = 1;
			 YDirection = 0;
			 Tick = 0;
			 break;
		 }
	 }
}

void Controls::XboxControls(float& XPos, float& YPos, int& XDirection, int& YDirection, int& Tick)
{
	//Gets the controller data.
	const HAPI_TControllerData& ControllarKeybinds = HAPI.GetControllerData(0);
	//checks the controller data to move the sptite.
	if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= MagSpeed;
		YPos += MagSpeed;
		switch (XDirection)
		{
		case 1:
			YDirection = 1;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 1;
			YDirection = 1;
			Tick = 0;
			break;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= MagSpeed;
		YPos -= MagSpeed;
		switch (XDirection)
		{
		case 1:
			YDirection = 2;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 1;
			YDirection = 2;
			Tick = 0;
			break;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += MagSpeed;
		YPos += MagSpeed;
		switch (XDirection)
		{
		case 0:
			YDirection = 1;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 1;
			Tick = 0;
			break;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE && ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += MagSpeed;
		YPos -= MagSpeed;
		switch (XDirection)
		{
		case 0:
			YDirection = 2;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 2;
			Tick = 0;
			break;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		YPos -= Speed;
		YDirection = 2;
		if (Tick < 3)
		{
			Tick++;
		}
		else
		{
			Tick = 0;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		YPos += Speed;
		YDirection = 1;
		if (Tick < 3)
		{
			Tick++;
		}
		else
		{
			Tick = 0;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos += Speed;
		switch (XDirection)
		{
		case 0:
			YDirection = 0;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 0;
			YDirection = 0;
			Tick = 0;
			break;
		}
	}
	else if (ControllarKeybinds.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -HK_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		XPos -= Speed;
		switch (XDirection)
		{
		case 1:
			YDirection = 0;
			if (Tick < 3)
			{
				Tick++;
			}
			else
			{
				Tick = 1;
			}
			break;
		default:
			XDirection = 1;
			YDirection = 0;
			Tick = 0;
			break;
		}
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



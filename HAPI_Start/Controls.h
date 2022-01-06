#pragma once
#include <HAPI_lib.h>


using namespace HAPISPACE;
class Controls
{
	private:
		int MaxControllars = HAPI.GetMaxControllers();
		const HAPI_TKeyboardData& KeyboardKeybinds = HAPI.GetKeyboardData();
		const HAPI_TSoundOptions& Volume = 0.025f;
		int PassedScreenWidth{ 0 };
		int PassedScreenHeight{ 0 };
		int PassedTexWidth{ 0 };
		int PassedTexHeight{ 0 };
		float Speed{ 4 };
		float MagSpeed = sqrt(pow(Speed, 2) / 2);
		int Count{ 0 };
	public:
		void KeyboardControls(float &XPos, float &YPos, int& XDirection, int& YDirection, int& Tick);

		void XboxControls(float &XPos, float &YPos, int& XDirection, int& YDirection, int& Tick);

		void Rumble(int Health);

		void GetValues();

		HAPI_TControllerData SetData();

		bool fireKeyboard();

		bool fireXbox();
};


#pragma once
#include <HAPI_lib.h>


using namespace HAPISPACE;

class Controls
{
	private:
		int MaxControllars = HAPI.GetMaxControllers();
		const HAPI_TKeyboardData& KeyboardKeybinds = HAPI.GetKeyboardData();
		int PassedScreenWidth{ 0 };
		int PassedScreenHeight{ 0 };
		int PassedTexWidth{ 0 };
		int PassedTexHeight{ 0 };
		float Speed{ 4 };
		float MagSpeed = sqrt(pow(Speed, 2) / 2);
		
	public:
		void KeyboardControls(float &XPos, float &YPos);

		void XboxControls(float &XPos, float &YPos);

		void Rumble(const float& XPos, const float& YPos);

		void GetValues();

		HAPI_TControllerData SetData();
};

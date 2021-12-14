#pragma once
#include <HAPI_lib.h>
#include <unordered_map>
using namespace HAPISPACE;

class Sprite;

class Render
{
	private:
		std::unordered_map<std::string, std::shared_ptr<Sprite>> R_SpriteMap;
		int R_ScreenWidth{ 1024 };
		int R_ScreenHeight{ 768 };
		BYTE* R_Screen{ nullptr };
	public:
		bool GetSprite(const std::string& SpriteName, const std::string& FileName);

		void PlayerSpriteRender(const std::string& SpriteName, float XPos, float YPos);

		void BackgroundRender(const std::string& SpriteName, float XPos, float YPos);

		bool Initialise();

		void Setbackgroundcolour();

		int ScreenWidth();

		int ScreenHeight();

};


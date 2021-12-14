#pragma once
#include <HAPI_lib.h>

class Border;

using namespace HAPISPACE;
class Sprite
{
	private:
		int S_TextureWidth{ 0 }, S_TextureHeight{ 0 };
		BYTE* S_TexturePointer{ nullptr };
		int EndOfTexOffset{ 0 };
		int TexOffset{ 0 };
		BYTE* TempScreen{ nullptr };
		BYTE* TempTexture{ nullptr };

	public:
		~Sprite()
		{
			delete[] S_TexturePointer;
		}

		bool GetSprite(const std::string& FileName);

		void Draw(float XPos, float YPos, BYTE* R_Screen, int R_ScreenWidth, int R_ScreenHight);

		void DrawBackground(float XPos, float YPos, BYTE* R_Screen, int R_ScreenWidth);

		Border PassTexBorder(const std::string& FileName);

};


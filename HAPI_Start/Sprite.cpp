#include "Sprite.h"
#include "Border.h"

bool Sprite::GetSprite(const std::string& FileName)
{
	//checks the sprite is in the files.
	if (!HAPI.LoadTexture(FileName, &S_TexturePointer, S_TextureWidth, S_TextureHeight))
	{
		HAPI.UserMessage("Missing texture", "Error");
		return false;
	}
	
	return true;
}

void Sprite::Draw(float XPos, float YPos, BYTE* R_Screen, int R_ScreenWidth, int R_ScreenHeight)
{
	//draws the sprite with alpha and clipping.
	Border ScreenBorder(0, R_ScreenWidth, 0, R_ScreenHeight);
	Border TexBorder(0, S_TextureWidth, 0, S_TextureHeight);
	Border ClippedTexBorder(TexBorder);
	ClippedTexBorder.Translate(XPos, YPos);
	ClippedTexBorder.ClipBorders(ScreenBorder);
	ClippedTexBorder.Translate(-XPos, -YPos);
	if (XPos < 0)
		XPos = 0;
	if (YPos < 0)
		YPos = 0;
	ClippedTexBorder.IsTheSpriteOffScreen();
	EndOfTexOffset = (ScreenBorder.Width() - ClippedTexBorder.Width()) * 4;
	TexOffset = (TexBorder.Width() - ClippedTexBorder.Width()) * 4;
	TempScreen = R_Screen + ((int)XPos + (int)YPos * (size_t)ScreenBorder.Width()) * 4;
	TempTexture = S_TexturePointer + (ClippedTexBorder.LeftSide + ClippedTexBorder.TopSide * (size_t)TexBorder.Width()) * 4;

	BYTE R ;
	BYTE G ;
	BYTE B ;

	BYTE RS ;
	BYTE GS ;
	BYTE BS ;

	for (size_t y = 0; y < ClippedTexBorder.Height(); y++)
	{
		for (size_t x = 0; x < ClippedTexBorder.Width(); x++)
		{
			BYTE a = TempTexture[3];
			if (a != 0)
			{
				if (a == 255)
				{
					memcpy(TempScreen, TempTexture, 4);
				}
				else
				{
					R = TempTexture[0];
					G = TempTexture[1];
					B = TempTexture[2];

					RS = TempScreen[0];
					GS = TempScreen[1];
					BS = TempScreen[2];

					float Alpha = a / 255.0f;

					TempScreen[0] = Alpha * R + (1.0f - Alpha) * RS;
					TempScreen[1] = Alpha * G + (1.0f - Alpha) * GS;
					TempScreen[2] = Alpha * B + (1.0f - Alpha) * BS;

				}
			}
			TempTexture += 4;
			TempScreen += 4;
		}

		TempTexture += TexOffset;
		TempScreen += EndOfTexOffset;
	}
}

void Sprite::DrawBackground(float XPos, float YPos, BYTE* R_Screen, int R_ScreenWidth)
{
	//draws the background.
	EndOfTexOffset = (R_ScreenWidth - S_TextureWidth) * 4;
	TempScreen = R_Screen + ((int)XPos + (int)YPos * (size_t)R_ScreenWidth) * 4;
	TempTexture = S_TexturePointer;
	for (size_t y = 0; y < S_TextureHeight; y++)
	{
		for (size_t x = 0; x < S_TextureWidth; x++)
		{
			memcpy(TempScreen, TempTexture, 4);
			TempTexture += 4;
			TempScreen += 4;
		}
		TempScreen += EndOfTexOffset;
	}
}

Border Sprite::PassTexBorder(float XPos, float YPos)
{
	/*if (!HAPI.LoadTexture(FileName, &S_TexturePointer, S_TextureWidth, S_TextureHeight))
	{
		HAPI.UserMessage("Missing texture", "Error");
	}*/

	Border TexBorder(0, S_TextureWidth - 15, 0, S_TextureHeight - 15);
	TexBorder.Translate(XPos, YPos);


	return TexBorder;
}


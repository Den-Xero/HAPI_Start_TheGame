#include "Render.h"
#include "Sprite.h"


bool Render::GetSprite(const std::string& SpriteName, const std::string& FileName)
{
	//makes a new sprite to add to the map.
	std::shared_ptr<Sprite> NewSprite = std::make_shared<Sprite>();
	//check the new sprite to see if it is a sprite the program can draw.
	if (!NewSprite->GetSprite(FileName))
	{
		HAPI.UserMessage("Getting Sprite failed", "Error");
		return false;
	}
	else
	{ 
		//saves the sprite.
		R_SpriteMap[SpriteName] = NewSprite;
		return true;
	}
}

void Render::PlayerSpriteRender(const std::string& SpriteName, float XPos, float YPos)
{
	//sees if it can find the sprite in the map and draws it.
	if (R_SpriteMap.find(SpriteName) == R_SpriteMap.end())
	{
		HAPI.UserMessage("Missing Sprite from map", "Error");
		return;
	}
	
	R_SpriteMap[SpriteName]->Draw(XPos, YPos, R_Screen, R_ScreenWidth, R_ScreenHeight);
}

void Render::BackgroundRender(const std::string& SpriteName, float XPos, float YPos)
{
	//sees if it can find the sprite in the map and draws it.
	if (R_SpriteMap.find(SpriteName) == R_SpriteMap.end())
	{
		HAPI.UserMessage("Missing BackGround from map", "Error");
		return;
	}

	R_SpriteMap[SpriteName]->DrawBackground(XPos, YPos, R_Screen, R_ScreenWidth);
}


bool Render::Initialise()
{
	//the initialision and setup.
	if (!HAPI.Initialise(R_ScreenWidth, R_ScreenHeight))
		return false;
	R_Screen = HAPI.GetScreenPointer();
	HAPI.SetShowFPS(true);
	HAPI.LimitFrameRate(120);
	return true;
}

void Render::Setbackgroundcolour()
{
	//sets colour behind the background and clears the screen.
	HAPI_TColour colour(0, 0, 100);
	size_t Offset = (0 + 0 * (size_t)R_ScreenWidth) * 4;
	BYTE* PixlePoint = R_Screen + Offset;
	for (size_t y = 0; y < R_ScreenHeight; y++)
	{
		for (size_t x = 0; x < R_ScreenWidth; x++)
		{
			//size_t Offset = (x + y * R_ScreenWidth) * 4;
			//BYTE* PixlePoint = R_Screen + Offset;
			memcpy(PixlePoint, &colour, 4);
			//*( (int32_t*)PixlePoint) = *(int32_t*)(&colour);
			PixlePoint += 4;
		}
	}
}

int Render::ScreenWidth()
{
	//setters
	return R_ScreenWidth;
}

int Render::ScreenHeight()
{
	//setters
	return R_ScreenHeight;
}

std::unordered_map<std::string, std::shared_ptr<Sprite>>& Render::PassMap()
{
	return R_SpriteMap;
}




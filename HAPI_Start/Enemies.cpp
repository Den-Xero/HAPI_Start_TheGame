#include "Enemies.h"


void Enemies::UpdateLoop(Render &Rend)
{
	RenderSprites(Rend);

	srand(time(NULL));

	if (Count == 100)
	{
		XPos += rand() % 50;

		YPos += rand() % 50;
		Count++;
	}
	else if(Count == 200)
	{
		XPos -= rand() % 50;

		YPos -= rand() % 50;
		Count = 0;
	}
	Count++;
}

void Enemies::RenderSprites(Render &Rend)
{
	Rend.PlayerSpriteRender(E_SpriteName, XPos, YPos);
}

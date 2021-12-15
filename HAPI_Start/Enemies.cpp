#include "Enemies.h"


void Enemies::UpdateLoop(Render &Rend)
{
	RenderSprite(Rend);

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

void Enemies::Setup()
{
	XPos = rand() % 1004 + 10;

	YPos = rand() % 748 + 10;
}

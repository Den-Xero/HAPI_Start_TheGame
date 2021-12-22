#include "Enemies.h"


void Enemies::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Health <= 0)
		Alive = false;

	if (Alive)
	{
		RenderSprite(Rend);

		srand(time(NULL));

		if (Count == 100)
		{
			XPos += rand() % 50;

			YPos += rand() % 50;
			Count++;
		}
		else if (Count == 200)
		{
			XPos -= rand() % 50;

			YPos -= rand() % 50;
			Count = 0;
		}
		Count++;
	}
}

Sides Enemies::GetSide()
{
	return Sides::EEnemy;
}

void Enemies::Setup()
{
	Alive = true;

	Health = 25;

	XPos = rand() % 1004 + 10;

	YPos = rand() % 748 + 10;
}

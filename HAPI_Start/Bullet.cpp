#include "Bullet.h"
#include "World.h"

void Bullet::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Health <= 0)
		Alive = false;

	if (Alive)
	{
		RenderSprite(Rend);

		YPos -= 10;

		if (YPos < -10)
		{
			Alive = false;
		}
	}
}

Sides Bullet::GetSide()
{
	return Sides::EPlayer;
}

void Bullet::Setup()
{
	Alive = false;

	Health = 1;

}



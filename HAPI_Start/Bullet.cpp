#include "Bullet.h"
#include "World.h"

void Bullet::UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec)
{
	if (Alive)
	{
		RenderSprite(Rend);

		YPos -= 10;

		if (YPos < -42)
		{
			Alive = false;
		}
	}
}

void Bullet::Setup()
{
	Alive = false;

	Health = 1;

}



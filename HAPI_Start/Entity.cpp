#include "Entity.h"
#include "Border.h"
#include "Sprite.h"
#include "Render.h"

bool Entity::IsAlive()
{
	return Alive;
}

void Entity::SetAlive()
{
	Alive = true;
	Health = 1;
}

void Entity::SetPositions(float X, float Y)
{
	XPos = X + 15;
	YPos = Y - 25;
}

bool Entity::CheckForCollision(std::shared_ptr<Entity> One, std::shared_ptr<Entity> Two, std::unordered_map<std::string, std::shared_ptr<Sprite>> Map)
{
	if (One->IsAlive() && Two->IsAlive())
	{
		Border BorderOne;
		Border BorderTwo;

		// Get One Collision rect
		BorderOne = Map[One->E_SpriteName]->PassTexBorder(One->XPos, One->YPos);
		// get other collision rect
		BorderTwo = Map[Two->E_SpriteName]->PassTexBorder(Two->XPos, Two->YPos);

		// check for collision
		if ((BorderOne.RightSide < BorderTwo.LeftSide || BorderOne.LeftSide > BorderTwo.RightSide) || (BorderOne.BottomSide < BorderTwo.TopSide || BorderOne.TopSide > BorderTwo.BottomSide))
		{
			//No Collision
			/*HAPI.UserMessage("No Collision", "Error");*/
			return false;
		}
		else
		{
			// Collision
			//HAPI.UserMessage("Collision", "Error");
			One->Health = One->Health - 5;
			Two->Health = Two->Health - 5;

			return true;
		}
	}
	
}

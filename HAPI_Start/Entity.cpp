#include "Entity.h"
#include "Border.h"
#include "Sprite.h"

bool Entity::CheckForCollision(Entity* One, Entity* Two)
{
	Border BorderOne;
	Border BorderTwo;
	Sprite Spr;

	// Get One Collision rect
	BorderOne = Spr.PassTexBorder(One->E_SpriteName);
	// get other collision rect
	BorderTwo = Spr.PassTexBorder(Two->E_SpriteName);

	// check for collision
	if (BorderOne.RightSide < BorderTwo.LeftSide || BorderOne.RightSide > BorderTwo.RightSide || BorderOne.BottomSide < BorderTwo.TopSide || BorderOne.TopSide > BorderTwo.TopSide)
	{
		//No Collision
		/*HAPI.UserMessage("No Collision", "Error");*/
		return false;
	}
	else
	{
		// Collision
		/*HAPI.UserMessage("Collision", "Error");*/
		return true;
	}
	
	
}

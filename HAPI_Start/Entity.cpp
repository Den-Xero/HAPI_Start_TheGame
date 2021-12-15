#include "Entity.h"
#include "Border.h"
#include "Sprite.h"

bool Entity::CheckForCollision(Entity* One, Entity* Two)
{
	Border BorderOne;
	Border BorderTwo;
	Sprite Spr;

	// Get One Collision rect
	BorderOne = Spr.PassTexBorder(One->E_FileName, One->XPos, One->YPos);
	// get other collision rect
	BorderTwo = Spr.PassTexBorder(Two->E_FileName, Two->XPos, Two->YPos);

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
		HAPI.UserMessage("Collision", "Error");
		return true;
	}
	
	
}

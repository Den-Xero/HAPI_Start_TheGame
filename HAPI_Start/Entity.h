#pragma once
#include "Render.h"
#include "Controls.h"


enum class Sides
{
	ENeutral,
	EPlayer,
	EEnemy
};

class Entity
{
	private:
	protected:
		std::string E_SpriteName;
	public:

		Entity(std::string SpriteName) : E_SpriteName(SpriteName) {};

		virtual ~Entity() = default;

		virtual void UpdateLoop(Render &Rend) = 0;

		void RenderSprite(Render& Rend);

		virtual Sides GetSide() const = 0;

		bool CheckForCollision(Entity Other)
		{
			// Get One Collision rect
			// get other collision rect
			// check for collision

			return false;
		}

		bool IsAnEnemy(Entity One, Entity Two)
		{
			if (One.GetSide() != Two.GetSide() )
			{
				return true;
			}
			else
			{
				return false;
			}
		}


};


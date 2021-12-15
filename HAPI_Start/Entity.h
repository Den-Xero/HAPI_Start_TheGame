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
		std::string E_FileName;
		float XPos{ 0 };
		float YPos{ 0 };
	public:

		Entity(std::string SpriteName, std::string FileName) : E_SpriteName(SpriteName), E_FileName(FileName) {};

		virtual ~Entity() = default;

		virtual void UpdateLoop(Render &Rend) = 0;

		void RenderSprite(Render& Rend)
		{
			Rend.PlayerSpriteRender(E_SpriteName, XPos, YPos);
		}

		virtual Sides GetSide() const = 0;

		bool CheckForCollision(Entity* One, Entity* Two);

		bool IsAnEnemy(Entity* One, Entity* Two)
		{
			if (One->GetSide() != Two->GetSide() )
			{
				return true;
			}
			else
			{
				return false;
			}
		}


};


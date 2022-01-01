#pragma once
#include "Render.h"
#include "Controls.h"
#include <unordered_map>

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

		bool Alive{ false };

		int Health{ 0 };

		int XDirection{ 0 };
		int YDirection{ 0 };
		int Tick{ 0 };

	public:

		Entity(std::string SpriteName) : E_SpriteName(SpriteName) {};

		virtual ~Entity() = default;

		virtual void UpdateLoop(Render &Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) = 0;

		virtual void Setup() = 0;

		void RenderSprite(Render& Rend)
		{
			Rend.PlayerSpriteRender(E_SpriteName, XPos, YPos);
		}

		virtual Sides GetSide() = 0;

		bool IsAlive();

		void SetAlive();

		void SetPositions(float X, float Y, int XDirection, int YDirection);

		bool CheckForCollision(std::shared_ptr<Entity> One, std::shared_ptr<Entity> Two, std::unordered_map<std::string, std::shared_ptr<Sprite>> Map);

		bool IsAnEnemy(std::shared_ptr<Entity> One, std::shared_ptr<Entity> Two)
		{
			if (One->GetSide() != Two->GetSide())
			{
				return true;
			}
			else
			{
				return false;
			}
		}


};


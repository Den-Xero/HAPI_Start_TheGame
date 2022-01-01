#include <HAPI_lib.h>
#include "World.h"
#include "Render.h"
#include "Player.h"
#include "Enemies.h"
#include "Bullet.h"
using namespace HAPISPACE;

void World::Run()
{
	Render W_Rend;
	//calls for initalise and setup
	if (!W_Rend.Initialise())
		return;

		
	LoadLevels(W_Rend);

	Map = W_Rend.PassMap();

	while (HAPI.Update())
	{
		//draws the background sprite to the window.
		W_Rend.BackgroundRender("BackGround", 0, 0);

		for (std::shared_ptr<Entity> P : W_EntityVec)
  			P->UpdateLoop(W_Rend, W_BulletStartIndex, W_BulletEndIdex, W_EntityVec);


		size_t i = 0;

		for (std::shared_ptr<Entity> P : W_EntityVec)
		{
			if (P->GetSide() != Sides::ENeutral)
			{
				for (size_t j = i + 1; j < W_EntityVec.size(); j++)
				{
					if (P->IsAnEnemy(W_EntityVec[i], W_EntityVec[j]))
					{
						P->CheckForCollision(W_EntityVec[i], W_EntityVec[j], Map);
					}
				}
			}
			i++;
		}

	}

}

void World::LoadLevels(Render &W_Rend)
{
	//gets and checks the sprite
	if (!W_Rend.GetSprite("BackGround", "Data\\background.png"))
	{
		HAPI.UserMessage("Missing Background tex", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteRight1", "Data\\PlayerYellowRight1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteRight2", "Data\\PlayerYellowRight2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteRight3", "Data\\PlayerYellowRight7.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteLeft1", "Data\\PlayerYellowLeft1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteLeft2", "Data\\PlayerYellowLeft2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSpriteLeft3", "Data\\PlayerYellowLeft7.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteDown1", "Data\\ZombieDown1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteDown2", "Data\\ZombieDown2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteDown3", "Data\\ZombieDown3.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteUp1", "Data\\ZombieUp1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteUp2", "Data\\ZombieUp2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteUp3", "Data\\ZombieUp3.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteLeft1", "Data\\ZombieLeft1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteLeft2", "Data\\ZombieLeft2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteLeft3", "Data\\ZombieLeft3.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteRight1", "Data\\ZombieRight1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteRight2", "Data\\ZombieRight2.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSpriteRight3", "Data\\ZombieRight3.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteLeft1", "Data\\BulletLeft1.png"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteLeft2", "Data\\BulletLeft5.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteLeft3", "Data\\BulletLeft9.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteUp1", "Data\\BulletUp1.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteUp2", "Data\\BulletUp5.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteUp3", "Data\\BulletUp9.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteRight1", "Data\\BulletRight1.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteRight2", "Data\\BulletRight5.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteRight3", "Data\\BulletRight9.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteDown1", "Data\\BulletDown1.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteDown2", "Data\\BulletDown5.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSpriteDown3", "Data\\BulletDown9.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	std::shared_ptr<Entity> NewEnemies1 = std::make_shared<Enemies>("EnemiesSpriteDown1");
	NewEnemies1->Setup();
	W_EntityVec.push_back(NewEnemies1);

	std::shared_ptr<Entity> NewEnemies2 = std::make_shared<Enemies>("EnemiesSpriteDown1");
	NewEnemies2->Setup();
	W_EntityVec.push_back(NewEnemies2);

	std::shared_ptr<Entity> NewEnemies3 = std::make_shared<Enemies>("EnemiesSpriteDown1");
	NewEnemies3->Setup();
	W_EntityVec.push_back(NewEnemies3);

	std::shared_ptr<Entity> NewEnemies4 = std::make_shared<Enemies>("EnemiesSpriteDown1");
	NewEnemies4->Setup();
	W_EntityVec.push_back(NewEnemies4);

	std::shared_ptr<Entity> NewEnemies5 = std::make_shared<Enemies>("EnemiesSpriteDown1");
	NewEnemies5->Setup();
	W_EntityVec.push_back(NewEnemies5);

	std::shared_ptr<Entity> NewPlayer = std::make_shared<Player>("PlayerSpriteRight1");
	NewPlayer->Setup();
	W_EntityVec.push_back(NewPlayer);

	W_BulletStartIndex = W_EntityVec.size() + 1;

	for (size_t i = 0; i < 20; i++)
	{
		std::shared_ptr<Entity> NewBullet1 = std::make_shared<Bullet>("BulletSpriteRight1");
		NewBullet1->Setup();
		W_EntityVec.push_back(NewBullet1);
	}

	W_BulletEndIdex = W_EntityVec.size();
}

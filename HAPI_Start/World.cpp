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
		//Calls the function to set the screen background colour.
		W_Rend.Setbackgroundcolour();

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

//Entity* World::PassVec(int i)
//{
//	return W_EntityVec[i];
//}

void World::LoadLevels(Render &W_Rend)
{
	//gets and checks the sprite
	if (!W_Rend.GetSprite("BackGround", "Data\\background.tga"))
	{
		HAPI.UserMessage("Missing Background tex", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("PlayerSprite", "Data\\playerSprite.tga"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("EnemiesSprite", "Data\\alphaThing.tga"))
	{
		HAPI.UserMessage("Missing PlayerSprite", "Error");
		return;
	}

	//gets and checks the sprite
	if (!W_Rend.GetSprite("BulletSprite", "Data\\Bullet1.png"))
	{
		HAPI.UserMessage("Missing BulletSprite", "Error");
		return;
	}

	std::shared_ptr<Entity> NewEnemies1 = std::make_shared<Enemies>("EnemiesSprite", "Data\\alphaThing.tga");
	NewEnemies1->Setup();
	W_EntityVec.push_back(NewEnemies1);

	std::shared_ptr<Entity> NewEnemies2 = std::make_shared<Enemies>("EnemiesSprite", "Data\\alphaThing.tga");
	NewEnemies2->Setup();
	W_EntityVec.push_back(NewEnemies2);

	std::shared_ptr<Entity> NewEnemies3 = std::make_shared<Enemies>("EnemiesSprite", "Data\\alphaThing.tga");
	NewEnemies3->Setup();
	W_EntityVec.push_back(NewEnemies3);

	std::shared_ptr<Entity> NewEnemies4 = std::make_shared<Enemies>("EnemiesSprite", "Data\\alphaThing.tga");
	NewEnemies4->Setup();
	W_EntityVec.push_back(NewEnemies4);

	std::shared_ptr<Entity> NewEnemies5 = std::make_shared<Enemies>("EnemiesSprite", "Data\\alphaThing.tga");
	NewEnemies5->Setup();
	W_EntityVec.push_back(NewEnemies5);

	std::shared_ptr<Entity> NewPlayer = std::make_shared<Player>("PlayerSprite", "Data\\playerSprite.tga");
	NewPlayer->Setup();
	W_EntityVec.push_back(NewPlayer);

	/*Bullet* NewBullet1 = new Bullet("BulletSprite", "Data\\Bullet1.png");
	NewBullet1->Setup();
	W_EntityVec.push_back(NewBullet1);*/

	W_BulletStartIndex = W_EntityVec.size() + 1;

	for (size_t i = 0; i < 50; i++)
	{
		std::shared_ptr<Entity> NewBullet1 = std::make_shared<Bullet>("BulletSprite", "Data\\Bullet1.png");
		NewBullet1->Setup();
		W_EntityVec.push_back(NewBullet1);
	}

	W_BulletEndIdex = W_EntityVec.size();
}

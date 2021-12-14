#include <HAPI_lib.h>
#include "World.h"
#include "Render.h"
#include "Player.h"
#include "Enemies.h"
using namespace HAPISPACE;

void World::Run()
{
	Render W_Rend;
	//calls for initalise and setup
	if (!W_Rend.Initialise())
		return;

		
	LoadLevels(W_Rend);

	Enemies NewEnemies1("EnemiesSprite");
	W_EntityVec.push_back(&NewEnemies1);

	Enemies NewEnemies2("EnemiesSprite");
	W_EntityVec.push_back(&NewEnemies2);

	Enemies NewEnemies3("EnemiesSprite");
	W_EntityVec.push_back(&NewEnemies3);

	Enemies NewEnemies4("EnemiesSprite");
	W_EntityVec.push_back(&NewEnemies4);

	Enemies NewEnemies5("EnemiesSprite");
	W_EntityVec.push_back(&NewEnemies5);

	Player NewPlayer("PlayerSprite");
	W_EntityVec.push_back(&NewPlayer);

	while (HAPI.Update())
	{
		//Calls the function to set the screen background colour.
		W_Rend.Setbackgroundcolour();

		//draws the background sprite to the window.
		W_Rend.BackgroundRender("BackGround", 0, 0);

		for (Entity* P : W_EntityVec)
			P->UpdateLoop(W_Rend);

		for (size_t i = 0; i < W_EntityVec.size(); i++)
		{
			if (W_EntityVec[i]->GetSide() != Sides::ENeutral)
			{
				for (size_t j = i + 1; j < W_EntityVec.size(); j++)
				{
					if(IsAnEnemy(W_EntityVec[i], W_EntityVec[j]))
				}
			}
		}

	}

}

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

	

	Player Player("e");

	Player.Setup();
}

#include <HAPI_lib.h>
#include "World.h"
#include "Render.h"
#include "Player.h"
#include "Enemies.h"
#include "Bullet.h"
using namespace HAPISPACE;

void World::Run(Render& W_Rend)
{
	if (!Restarted)
	{
		//calls for initalise and setup
		if (!W_Rend.Initialise())
			return;

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
		//Loads sounds needed for game.
		HAPI.LoadSound("Data\\laserRetro_002.ogg");
		HAPI.LoadSound("Data\\slime_000.ogg");
		//Message box for user to read to get to know the game.
		HAPI.UserMessage("Use WASD to move, F to shoot, damage is set to 5. Player health is set to 100, enemies are set to 25. You get one point every tick, you get ten points every kill and lose (E = one, M = two, H = four) health every enemy the gets away.", "Game rules");
		
		do
		{
			HAPI.UserTextEntry("Pick difficulty", Difficulty, "E for easy, M for medium, H for hard.");
		} while (Difficulty != "E" && Difficulty != "M" && Difficulty != "H");
		
	}

	//Load the sprites need for game.
	LoadLevel1(W_Rend);

	//gets sprite map for collisions uses.
	Map = W_Rend.PassMap();

	//plays background sound.
	HAPI_TSoundOptions Background{ 0.025f, true, 0, 1.0f };
	HAPI.PlayStreamedMedia("Data\\Summer-Nature-Bird-Sounds.wav", Background, BackgroundID);

	while (HAPI.Update())
	{
		//draws the background sprite to the window.
		W_Rend.BackgroundRender("BackGround", 0, 0);

		//puts score on screen
		std::string PlayerScore = "Your score is: " + std::to_string(Score);
		HAPI.RenderText(0, 20, HAPI_TColour::CYAN, PlayerScore, 20, eBold);

		//Update loop for game.
		for (std::shared_ptr<Entity> P : W_EntityVec)
  			P->UpdateLoop(W_Rend, W_BulletStartIndex, W_BulletEndIdex, W_EntityVec, Score, PlayerTickDamage, Difficulty);

		//Collision
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

		//enemies respawns after they dead.
		for (size_t i = W_EnemyStartIndex; i <= W_EnemyEndIndex; i++)
		{
			if (!W_EntityVec[i]->IsAlive())
			{
				W_EntityVec[i]->Setup();
			}
		}

		//ticks score
		if (ScoreBreak == 50)
		{
			Score++;
			ScoreBreak = 0;
		}
		else
		{
			ScoreBreak++;
		}

	}

}

//stops rend from initialising twice.
void World::SetRestarted()
{
	Restarted = true;
}

void World::LoadLevel1(Render &W_Rend)
{
	//empties vector for restart.
	W_EntityVec.clear();

	//makes enemies.
	W_EnemyStartIndex = W_EntityVec.size();
	for (size_t i = 0; i < 8; i++)
	{
		std::shared_ptr<Entity> NewEnemies1 = std::make_shared<Enemies>("EnemiesSpriteDown1");
		NewEnemies1->Setup();
		W_EntityVec.push_back(NewEnemies1);
	}
	W_EnemyEndIndex = W_EntityVec.size();

	//makes bullets
	W_BulletStartIndex = W_EntityVec.size() + 1;
	for (size_t i = 0; i < 10; i++)
	{
		std::shared_ptr<Entity> NewBullet1 = std::make_shared<Bullet>("BulletSpriteRight1");
		NewBullet1->Setup();
		W_EntityVec.push_back(NewBullet1);
	}
	W_BulletEndIdex = W_EntityVec.size();

	//makes player.
	std::shared_ptr<Entity> NewPlayer = std::make_shared<Player>("PlayerSpriteRight1");
	NewPlayer->Setup();
	W_EntityVec.push_back(NewPlayer);
}

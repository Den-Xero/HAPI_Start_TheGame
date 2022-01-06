#pragma once
#include <vector>
#include <unordered_map>

class Render;

class Entity;

class Sprite;

class World
{
	private:
		void LoadLevel1(Render &W_Rend);

		void LoadLevel2(Render& W_Rend);

		void LoadLevel3(Render& W_Rend);

		void LoadLevel4(Render& W_Rend);

		std::vector<std::shared_ptr<Entity>> W_EntityVec;

		int W_BulletStartIndex{ 0 };

		int W_BulletEndIdex{ 0 };

		int W_EnemyStartIndex{ 0 };

		int W_EnemyEndIndex{ 0 };

		int W_NumOfEnemies{ 0 };

		int W_NumOfAliveEnemies{ 0 };

		std::unordered_map<std::string, std::shared_ptr<Sprite>> Map;

		int Score{0};

		int ScoreBreak{ 0 };

		int LevelCounter{ 0 };

		bool Restarted{ false };

		int PlayerTickDamage{ 0 };

		int BackgroundID{ 0 };

		std::string Difficulty;
	public:
		~World()
		{
			/*for (Entity* P : W_EntityVec)
				delete [] P;*/

		}

		void Run(Render& W_Rend);

		void SetRestarted();


};


#pragma once
#include <vector>
#include <unordered_map>

class Render;

class Entity;

class Sprite;

class World
{
	private:
		void LoadLevels(Render &W_Rend);

		std::vector<std::shared_ptr<Entity>> W_EntityVec;

		int W_BulletStartIndex{ 0 };

		int W_BulletEndIdex{ 0 };

		std::unordered_map<std::string, std::shared_ptr<Sprite>> Map;
	public:
		~World()
		{
			/*for (Entity* P : W_EntityVec)
				delete [] P;*/

		}

		void Run();

		//Entity* PassVec(int i);
};


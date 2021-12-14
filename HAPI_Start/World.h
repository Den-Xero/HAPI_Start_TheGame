#pragma once
#include <vector>
class Render;

class Entity;

class World
{
	private:
		void LoadLevels(Render &W_Rend);

		std::vector<Entity*> W_EntityVec;

	public:
		~World()
		{
			
		}

		void Run();

		
};


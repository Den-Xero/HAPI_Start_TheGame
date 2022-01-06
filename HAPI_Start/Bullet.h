#pragma once
#include "Entity.h"
class Bullet :
    public Entity
{
    private:

    public:

        Bullet(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec, int& Score, int& PlayerTickDamage, std::string Difficulty) override final;

        Sides GetSide() override final;

        void Setup() override final;


};


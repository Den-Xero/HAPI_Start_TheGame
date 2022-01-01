#pragma once
#include "Entity.h"
class Bullet :
    public Entity
{
    private:

    public:

        Bullet(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) override final;

        Sides GetSide() override final;

        void Setup() override final;


};


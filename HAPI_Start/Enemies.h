#pragma once
#include "Entity.h"


class Enemies :
    public Entity
{
    private:

        int Count{0};

    public:
        Enemies(std::string SpriteName, std::string FileName) : Entity(SpriteName, FileName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) override final;

        Sides GetSide() override final { return Sides::EEnemy; }

        void Setup() override final;
};


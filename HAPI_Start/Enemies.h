#pragma once
#include "Entity.h"


class Enemies :
    public Entity
{
    private:

        int Count{0};

    public:
        Enemies(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) override final;

        Sides GetSide() override final;

        void Setup() override final;
};


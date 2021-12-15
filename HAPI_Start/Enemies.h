#pragma once
#include "Entity.h"


class Enemies :
    public Entity
{
    private:

        int Count{0};

    public:
        Enemies(std::string SpriteName, std::string FileName) : Entity(SpriteName, FileName) {};

        void UpdateLoop(Render &Rend) override final;

        Sides GetSide() const override { return Sides::EEnemy; }

        void Setup();
};


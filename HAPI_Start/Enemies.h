#pragma once
#include "Entity.h"


class Enemies :
    public Entity
{
    private:
        float XPos = rand() % 1004 + 10;

        float YPos = rand() % 748 + 10;

        int Count{0};
    public:
        Enemies(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render &Rend) override final;

        Sides GetSide() const override { return Sides::EEnemy; }

        void RenderSprites(Render &Rend);


};


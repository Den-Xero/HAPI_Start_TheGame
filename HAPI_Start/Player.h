#pragma once
#include "Entity.h"

class Controls;

class Player :
    public Entity
{
    private:
        struct Positions
        {
            float X, Y;
        };

        Positions Pos = { 100, 200 };

        Controls P_Con;

       HAPI_TControllerData ControllarData;
    public:
        Player(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render &Rend) override final;

        Sides GetSide() const override { return Sides::EPlayer; }

        void RenderSprite(Render &Rend);

        void Setup();
};


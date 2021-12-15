#pragma once
#include "Entity.h"

class Controls;

class Player :
    public Entity
{
    private:

        Controls P_Con;

       HAPI_TControllerData ControllarData;
    public:
        Player(std::string SpriteName, std::string FileName) : Entity(SpriteName, FileName) {};

        void UpdateLoop(Render &Rend) override final;

        Sides GetSide() const override { return Sides::EPlayer; }

        void Setup();
};


#pragma once
#include "Entity.h"

class Controls;

class Player :
    public Entity
{
    private:

       Controls P_Con;

       HAPI_TControllerData ControllarData;

       std::shared_ptr<Entity> One{NULL};

       bool CheckAlive{false};
    public:
        Player(std::string SpriteName, std::string FileName) : Entity(SpriteName, FileName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) override final;

        Sides GetSide() override final { return Sides::EPlayer; }

        void Setup() override final;

};


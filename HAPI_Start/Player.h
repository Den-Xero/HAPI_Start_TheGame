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
        Player(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec) override final;

        Sides GetSide() override final;

        void Setup() override final;

};


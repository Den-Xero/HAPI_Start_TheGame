#pragma once
#include "Entity.h"

class Controls;

class Player :
    public Entity
{
    private:

       Controls P_Con;

       HAPI_TControllerData ControllarData;

       HAPI_UserResponse Response;

    public:
        Player(std::string SpriteName) : Entity(SpriteName) {};

        void UpdateLoop(Render& Rend, int BulletStart, int BulletEnd, std::vector<std::shared_ptr<Entity>>& Vec, int& Score, int& PlayerTickDamage, std::string Difficulty) override final;

        Sides GetSide() override final;

        void Setup() override final;

};


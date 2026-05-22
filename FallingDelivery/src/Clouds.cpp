//
// Created by leonv on 22/05/2026.
//
#include <iostream>
#include "Clouds.h"

namespace game
{
    Clouds::Clouds(const char* asset): image(LoadTexture(asset)),
    speed(2),
    direction (GetRandomValue(-1, 1)),
    position({(float)GetRandomValue(0, 1200), 800}){
        std::cout << direction;
    }

    void Clouds::Draw()
    {
        DrawTextureEx(image, position, 0, 0.2, WHITE);
    }


    void Clouds::Update() {
        position.y -= speed;

        if (position.x + image.width >= 1200 || position.x -image.width <= 0) {
            direction *= -1;
        }
    }

    Clouds::~Clouds() {
        UnloadTexture(image);
    }

} // game
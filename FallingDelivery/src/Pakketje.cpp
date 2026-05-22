//
// Created by leonv on 22/05/2026.
//

#include <iostream>
#include "Pakketje.h"

namespace game
{
    Pakketje::Pakketje(const char* asset): image(LoadTexture(asset)),
    speed(2),
    direction (GetRandomValue(-1, 1)),
    position({(float)GetRandomValue(0, 1200), 800}){
        std::cout << direction;
    }

    void Pakketje::Draw()
    {
        DrawTextureEx(image, position, 0, 0.2, WHITE);
    }

    Vector2 Pakketje::GetPosition() {
        return position;
    }

    void Pakketje::Update() {
        position.y -= speed;

        if (position.x + image.width >= 1200 || position.x -image.width <= 0) {
            direction *= -1;
        }
    }

    Pakketje::~Pakketje() {
        UnloadTexture(image);
    }

} // game
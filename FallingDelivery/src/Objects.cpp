//
// Created by staut on 5/22/2026.
//

#include "Objects.h"
#include "raylib.h"
#include <iostream>

namespace game {
    Objects::Objects(const char* asset): image(LoadTexture(asset)),
    speed(2),
    direction (GetRandomValue(-1, 1)),
    position({(float)GetRandomValue(0, 1200), 800}){
        std::cout << direction;
    }

    void Objects::Draw() {
        DrawTextureEx(image, position, 0, 0.2, WHITE);

    }

    Vector2 Objects::GetPosition() {
        return position;
    }

    void Objects::Update() {
        position.x += speed * direction;
        position.y -= speed;

        if (position.x + image.width >= 1200 || position.x -image.width <= 0) {
            direction *= -1;
        }
    }

    Objects::~Objects() {
        UnloadTexture(image);
    }
} // game
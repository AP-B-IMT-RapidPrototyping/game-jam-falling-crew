//
// Created by staut on 5/22/2026.
//

#include "Objects.h"
#include "raylib.h"
#include <iostream>

namespace game {
    Objects::Objects(): speed(2),
    type(GetRandomValue(0, 1)),
    direction (GetRandomValue(-1, 1))
    {
        switch (type) {
            case 0:
                image = LoadTexture("assets/rocket.png");
                position = {(float)GetRandomValue(0, 1200), 800};
                break;
            case 1:
                image = LoadTexture("assets/bird.png");
                position = {0, (float)GetRandomValue(0, 800)};
                break;

        }
    }

    void Objects::Draw() {
        DrawTextureEx(image, position, 0, 0.2, WHITE);

    }

    Vector2 Objects::GetPosition() {
        return position;
    }

    void Objects::Update() {
        if (type == 0) {
            position.x += speed * direction;
            position.y -= speed;

            if (position.x + image.width >= 1200 || position.x -image.width <= 0) {
                direction *= -1;
            }
        }
        else if (type == 1) {
            position.x += speed;
            position.y -= speed / 2;
        }
    }

    Objects::~Objects() {
        UnloadTexture(image);
    }
} // game
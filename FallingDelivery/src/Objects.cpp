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
            try
            {
                image = LoadTexture("assets/rocket.png");
            }
            catch (const std::runtime_error& e)
            {
                std::cerr << "Fout opgetreden: " << e.what() << std::endl;
            }

                position = {(float)GetRandomValue(10, 1150), 790};
                collisionRange = 80.0f;
                break;
            case 1:
            try
            {
                image = LoadTexture("assets/bird.png");
            }
            catch (const std::runtime_error& e)
            {
                std::cerr << "Fout opgetreden: " << e.what() << std::endl;
            }
                position = {10, (float)GetRandomValue(10, 790)};
                collisionRange = 60.0f;
                break;

        }
    }

    void Objects::Draw() {
        if (type == 0) {
            DrawTextureEx(image, position, 0, 0.2, WHITE);
        }
        else if (type == 1) {
            DrawTextureEx(image, position, 0, 0.15, WHITE);
        }

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
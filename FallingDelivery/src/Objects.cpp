//
// Created by staut on 5/22/2026.
//

#include "Objects.h"
#include "raylib.h"

namespace game {
    Objects::Objects(const char* asset): speed(1) {
        image = LoadTexture(asset);
        position = {(float)image.width, 800};
        direction = GetRandomValue(-1,2);
    }

    void Objects::Draw() {
        DrawTexture(image, position.x, position.y, WHITE);
    }

    Vector2 Objects::GetPosition() {
        return position;
    }

    void Objects::Update() {
        position.x += speed * direction;
        position.y -= speed;
    }

    Objects::~Objects() {
        UnloadTexture(image);
    }
} // game
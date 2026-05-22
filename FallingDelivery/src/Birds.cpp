//
// Created by staut on 5/22/2026.
//

#include "Birds.h"

namespace game {
    Birds::Birds(const char* asset): image(LoadTexture(asset)),
    speed(3),
    position({0,(float)GetRandomValue(image.height, 1200 - image.height)}) {

    }

    void Birds::Draw() {
        DrawTextureEx(image, position, 0, 0.2, WHITE);

    }

    void Birds::Update() {
        position.x += speed;
        position.y -= speed / 2;
    }

    Birds::~Birds() {
        UnloadTexture(image);
    }

} // game
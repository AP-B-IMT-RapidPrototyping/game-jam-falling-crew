//
// Created by staut on 5/22/2026.
//

#include "Birds.h"

namespace game {
    Birds::Birds(const char* asset): image(LoadTexture(asset)),
    speed(1),
    position({300,(float)GetRandomValue(image.height, 1200 - image.height)}) {

    }

    void Birds::Draw() {
        DrawTexture(image, position.x, position.y, WHITE);

    }

    void Birds::Update() {
        position.x += speed;
    }

    Birds::~Birds() {
        UnloadTexture(image);
    }

} // game
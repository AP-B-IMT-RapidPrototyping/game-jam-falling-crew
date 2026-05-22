//
// Created by staut on 5/22/2026.
//

#ifndef FALLINGDELIVERY_PLAYER_H
#define FALLINGDELIVERY_PLAYER_H

#include "raylib.h"
#include <string>

namespace game {
    class Player {
    private:
        Texture2D image;
        Vector2 position;
        float speed;
    public:
        Player(const std::string& imagePath);
        void Draw();
        void Update();
        Vector2 GetPosition();
        ~Player();
    };
} // Game

#endif //FALLINGDELIVERY_PLAYER_H
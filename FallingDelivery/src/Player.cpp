//
// Created by staut on 5/22/2026.
//
#include <iostream>
#include "Player.h"
#include "raylib.h"

namespace game
{
    Player::Player(const std::string& imagePath)
        :image {LoadTexture(imagePath.c_str())}
        ,position{500.0f, 100.0f}
        ,speed{300.0f}
    {
        std::cout << "Player aangemaakt\n";
    }

    Player::~Player()
    {
        UnloadTexture(image);
    }

    void Player::Update()
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT) && position.x <= 1000) position.x += speed * dt;
        if (IsKeyDown(KEY_LEFT) && position.x >= 0)  position.x -= speed * dt;
        if (IsKeyDown(KEY_DOWN) && position.y <=  650)  position.y += speed * dt;
        if (IsKeyDown(KEY_UP) && position.y >= 0)    position.y -= speed * dt;

    }

    void Player::Draw()
    {
     DrawTextureEx(image, position, 0,0.2, WHITE);
    }

    Vector2 Player::GetPosition() {
        return position;
    }
} // Game
#include <iostream>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"
#include <vector>

#include "raymath.h"

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;
     int playerLives = 2;

    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    std::vector<game::Objects*> objects;

    game::Player player ("assets/Skydiver.png");


    while (!WindowShouldClose() && playerLives != 0)
    {
        if (playerLives <= 0) {
            player.~Player();
            delete &player;

        }
        if (IsKeyPressed(KEY_S)) {
            objects.push_back(new game::Objects());
        }

        player.Update();
        BeginDrawing();
        ClearBackground(SKYBLUE);

        player.Draw();

        for (game::Objects* o: objects) {
            o->Update();
            o->Draw();
        }

        auto it = objects.begin();

        while (it != objects.end()) {
            game::Objects* o = *it;

            float distance = Vector2Distance(player.GetPosition(), o->GetPosition());

            if (distance <= 80.0f && playerLives != 0) {
                playerLives--;
                delete o;
                it = objects.erase(it);
            }
            else if (o->GetPosition().y  < 0) {
                delete o;
                it =objects.erase(it);
                std::cout << "object removed";
            }
            else {
                ++it;
            }
        }
        EndDrawing();

    }
    CloseWindow();
    return 0;
}

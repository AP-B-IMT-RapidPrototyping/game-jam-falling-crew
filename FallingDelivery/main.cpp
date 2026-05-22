#include <iostream>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"
#include "Birds.h"
#include <vector>

#include "raymath.h"

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;
     int playerLives = 2;

    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    std::vector<game::Objects*> objects;
    std::vector<game::Birds*> birds;
    game::Player player ("assets/Skydiver.png");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_S)) {
            objects.push_back(new game::Objects("assets/rocket.png"));
        }
        if (IsKeyPressed(KEY_E)) {
            birds.push_back(new game::Birds("assets/bird.png"));
        }

        player.Update();
        BeginDrawing();
        ClearBackground(SKYBLUE);

        player.Draw();

        for (game::Objects* o: objects) {
            o->Update();
            o->Draw();
        }
        for (game::Birds* b: birds) {
            b->Update();
            b->Draw();
        }
        auto it = objects.begin();
        auto itBird = birds.begin();
        while (it != objects.end()) {
            game::Objects* o = *it;
            float distance = Vector2Distance(player.GetPosition(), o->GetPosition());
            if (distance < 30.0f && playerLives != ) {
                playerLives--;
            }
            if (o->GetPosition().y  < 0) {
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

#include <iostream>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"
#include "Birds.h"
#include <vector>

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;

    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    std::vector<game::Objects*> objects;
    std::vector<game::Birds*> birds;
    game::Player player ("assets/Skydiver.png");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_S)) {
            objects.push_back(new game::Objects("assets/hellportal.png"));
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
        while (it != objects.end()) {
            game::Objects* o = *it;

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
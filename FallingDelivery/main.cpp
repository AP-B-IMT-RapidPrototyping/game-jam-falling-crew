#include <iostream>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"
#include <vector>

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;
    std::vector<game::Objects*> objects;
    auto object = new game::Objects("FallingDelivery/assets/hellportal.png");
    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_S)) {
            objects.push_back(new game::Objects("FallingDelivery/assets/hellportal.png"));
        }
        BeginDrawing();
        ClearBackground(SKYBLUE);
        for (game::Objects* o: objects) {
            o->Update();
            o->Draw();
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
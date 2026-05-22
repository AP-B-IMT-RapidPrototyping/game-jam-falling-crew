#include <iostream>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;

    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(SKYBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include <iostream>
#include <string>
#include "raylib.h"
#include "Objects.h"
#include "Player.h"
#include <vector>

#include "Pakketje.h"
#include "raymath.h"

int main() {
    const int screenWith = 1200;
    const int screenHeight = 800;
    int playerLives = 2;
    int score = 0;
    //timers
    int timerObject = 0;
    int timerPackets = 0;
    int timer = 3600;
    int counter;

    InitWindow(screenWith, screenHeight, "Falling Delivery");
    SetTargetFPS(60);

    std::vector<game::Objects*> objects;
    std::vector<game::Pakketje*> pakket;
    game::Player player ("assets/Skydiver.png");


    while (!WindowShouldClose()  && timer != 0 )
    {
        if (playerLives != 0) {
            counter = timer / 60;

            if (timerObject >= 60) {
                objects.push_back(new game::Objects());
                timerObject = 0;
            }
            else {
                timerObject++;
            }

            if (timerPackets >= 360) {
                pakket.push_back(new game::Pakketje("assets/pakketje.png"));
                timerPackets = 0;
            }
            else {
                timerPackets++;
            }

            player.Update();
            BeginDrawing();
            ClearBackground(SKYBLUE);

            player.Draw();

            for (game::Objects* o: objects) {
                o->Update();
                o->Draw();
            }

            for (game::Pakketje* p: pakket) {
                p->Update();
                p->Draw();
            }

            DrawText(std::to_string(score).c_str(), GetScreenWidth()/ 2, 10, 70, WHITE);
            DrawText(std::to_string(playerLives).c_str(), 10, 2, 70, WHITE);
            DrawText(std::to_string(counter).c_str(), GetScreenWidth() - 90, 2, 70, WHITE);
            auto it = objects.begin();
            while (it != objects.end()) {
                game::Objects* o = *it;

                float distance = Vector2Distance(player.GetPosition(), o->GetPosition());

                if (distance <= o->collisionRange && playerLives != 0) {
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
            auto it2 = pakket.begin();
            while (it2 != pakket.end()) {
                game::Pakketje* p = *it2;

                float distance = Vector2Distance(player.GetPosition(), p->GetPosition());

                if (distance <= 80.0f) {
                    delete p;
                    it2 = pakket.erase(it2);
                    score++;
                }
                else {
                    ++it2;
                }
            }
            /*if (playerLives <= 0) {
                player.~Player();

            }*/
            EndDrawing();
            timer--;
        }
        else {
            BeginDrawing();
            ClearBackground(GRAY);
            DrawText("GAME OVER", GetScreenWidth() / 4, GetScreenHeight() / 2.5, 100, RED);
            DrawText(std::to_string(score).c_str(), GetScreenWidth() / 2, GetScreenHeight() / 2, 60, WHITE);
            EndDrawing();
        }

    }

    CloseWindow();
    return 0;
}
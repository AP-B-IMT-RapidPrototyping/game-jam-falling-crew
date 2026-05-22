//
// Created by leonv on 22/05/2026.
//

#ifndef FALLINGDELIVERY_PAKKETJE_H
#define FALLINGDELIVERY_PAKKETJE_H
#include "Objects.h"

namespace game
{
    class Pakketje
    {
    private:
        Texture2D image;
        Vector2 position;
        int direction;
        int speed;
    public:
        Pakketje(const char* asset);
        void Draw();
        void Update();
        Vector2 GetPosition();
        ~Pakketje();
    };
} // game

#endif //FALLINGDELIVERY_PAKKETJE_H
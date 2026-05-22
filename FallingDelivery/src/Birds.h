//
// Created by staut on 5/22/2026.
//

#ifndef FALLINGDELIVERY_BIRDS_H
#define FALLINGDELIVERY_BIRDS_H
#include "Objects.h"

namespace game {
    class Birds{
    private:
        Texture2D image;
        Vector2 position;
        int speed;
    public:
        Birds(const char* asset);
        void Draw();
        void Update();
        Vector2 GetPosition();
        ~Birds();
    };
} // game

#endif //FALLINGDELIVERY_BIRDS_H
//
// Created by leonv on 22/05/2026.
//

#ifndef FALLINGDELIVERY_CLOUDS_H
#define FALLINGDELIVERY_CLOUDS_H
#include "raylib.h"
namespace game
{
    class Clouds
    {
    private:
        Texture2D image;
        Vector2 position;
        int direction;
        int speed;
    public:
        Clouds(const char* asset);
        void Draw();
        void Update();
        ~Clouds();
    };
}




#endif //FALLINGDELIVERY_CLOUDS_H
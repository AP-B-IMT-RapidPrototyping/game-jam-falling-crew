//
// Created by staut on 5/22/2026.
//

#ifndef FALLINGDELIVERY_OBJECTS_H
#define FALLINGDELIVERY_OBJECTS_H
#include "raylib.h"
namespace game {
    class Objects {
    private:
        int type;
         Texture2D image;
         Vector2 position;
        int direction;
        int speed;
    public:
        float collisionRange;
        Objects();
        void Draw();
        void Update();
        Vector2 GetPosition();
        ~Objects();
    };
} // game

#endif //FALLINGDELIVERY_OBJECTS_H
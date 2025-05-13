#pragma warning( push , 0)
#include <iostream>
#include "raylib.h"
#include <filesystem>
#include "Tank.h"
#include "Bullet.h"
#include <vector>
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS

#pragma warning(pop)

using namespace MathClasses;

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Tank Game - Bradley Robertson");

    // Loading in textures for the tank body, turret, and bullet
    Texture2D bodyTexture = LoadTexture("../assets/images/body.png");
    Texture2D turretTexture = LoadTexture("../assets/images/turret.png");
    Texture2D bulletTexture = LoadTexture("../assets/images/bullet.png");

    // Initialise the starting location of the tank
    Tank tank(MathClasses::Vector3{screenWidth / 2.0f, screenHeight / 2.0f, 0.0f}, bodyTexture, turretTexture, bulletTexture);

    // Box position and size
    Vector2 boxPosition = {1000, 100};
    Vector2 boxSize = {140, 140}; 
    Color boxColor = GREEN;


    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        tank.Update(deltaTime);

        // Destroy bullets that are out of bounds or have collided with the box
        tank.GetBullets().erase(std::remove_if(tank.GetBullets().begin(), tank.GetBullets().end(), [&](const Bullet& bullet) {
            return bullet.IsOutOfBounds() || bullet.BoxCollision(boxPosition, boxSize);
            }), tank.GetBullets().end());

        BeginDrawing();

        ClearBackground(RAYWHITE);

        tank.Draw();

        // Draw the box for testing collision
        DrawRectangleV(boxPosition, boxSize, boxColor);

        EndDrawing();
    }

    // Unloading the textures
    UnloadTexture(bodyTexture);
    UnloadTexture(turretTexture);
    UnloadTexture(bulletTexture);

    CloseWindow();

    return 0;
}
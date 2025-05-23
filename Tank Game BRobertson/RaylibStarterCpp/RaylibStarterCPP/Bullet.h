#pragma once
#include "raylib.h"
#include "Vector3.h"

using namespace MathClasses;

// Represents a bullet fired by the tank
class Bullet
{
public:
    // Constructs a bullet with a given position, direction, and texture
    Bullet(MathClasses::Vector3 position, MathClasses::Vector3 direction, Texture2D texture);

    // Updates the bullet's position based on its speed and direction
    void Update(float deltaTime);

    // Draws the bullet on the screen with the correct rotation
    void Draw() const;

    // Checks if the bullet has moved outside the screen bounds
    bool IsOutOfBounds() const;

    // Checks if the bullet collides with a given box (AABB)
    bool BoxCollision(const Vector2& boxPos, const Vector2& boxSize) const;

    // Returns the current position of the bullet
    MathClasses::Vector3 GetPosition() const;

private:
    MathClasses::Vector3 position;   // Current position of the bullet
    MathClasses::Vector3 direction;  // Normalized direction vector
    float speed;                     // Movement speed of the bullet
    float rotation;                  // Rotation angle for rendering
    Texture2D texture;               // Texture used to draw the bullet
};
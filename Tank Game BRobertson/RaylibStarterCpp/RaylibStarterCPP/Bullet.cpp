#include <iostream>
#include "Bullet.h"
#include "Vector3.h"
using namespace MathClasses;

// Constructor initialising bullet properties
Bullet::Bullet(MathClasses::Vector3 position, MathClasses::Vector3 direction, Texture2D texture)
    : position(position), direction(direction.Normalised()), texture(texture), speed(450.0f)
{
    // Adjusting the rotation to correct the bullet's orientation
    rotation = atan2f(direction.y, direction.x) * RAD2DEG + 90.0f;
}

// Update the bullet's position based on its speed and direction
void Bullet::Update(float deltaTime)
{
    position = position + direction * speed * deltaTime;
}

// Draw the bullet with the correct rotation
void Bullet::Draw() const
{
    DrawTexturePro(texture, {0, 0, (float)texture.width, (float)texture.height},
                  {position.x, position.y, (float)texture.width, (float)texture.height},
                  {texture.width / 2.0f, texture.height / 2.0f}, rotation, WHITE);
}

// Check if the bullet has hit the edge of the screen
bool Bullet::IsOutOfBounds() const
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight();
}

// Check for bullet collision with the box
bool Bullet::BoxCollision(const Vector2& boxPos, const Vector2& boxSize) const
{
        return (position.x > boxPos.x && position.x < (boxPos.x + boxSize.x) &&
        position.y > boxPos.y && position.y < (boxPos.y + boxSize.y));
}

// Get the current position of the bullet
MathClasses::Vector3 Bullet::GetPosition() const
{
    return position;
}
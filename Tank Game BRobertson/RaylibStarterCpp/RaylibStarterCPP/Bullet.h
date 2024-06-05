#pragma once
#include "raylib.h"
#include "Vector3.h"

using namespace MathClasses;

class Bullet
{
public:
    Bullet(MathClasses::Vector3 position, MathClasses::Vector3 direction, Texture2D texture);
    void Update(float deltaTime);
    void Draw();
    bool IsOutOfBounds() const;
    bool BoxCollision(const Vector2& boxPos, const Vector2& boxSize) const;
    MathClasses::Vector3 GetPosition() const;

private:
    MathClasses::Vector3 position;
    MathClasses::Vector3 direction;
    float speed;
    float rotation;
    Texture2D texture;
};
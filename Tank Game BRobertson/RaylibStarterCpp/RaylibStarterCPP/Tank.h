#pragma once
#include "raylib.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Bullet.h"
#include <vector>

using namespace MathClasses;

class Tank
{
public:
    Tank(MathClasses::Vector3 position, Texture2D bodyTexture, Texture2D turretTexture, Texture2D bulletTexture);
    void Update(float deltaTime);
    void Draw();
    void RotateBody(float angle);
    void MoveBody(float distance);
    void RotateTurret(float angle);
    void FireBullet();
    MathClasses::Vector3 GetPosition() const;
    Matrix3 GetTurretTransform() const;
    std::vector<Bullet>& GetBullets();

private:
    MathClasses::Vector3 position;
    float bodyRotation;
    float turretRotation;
    Texture2D bodyTexture;
    Texture2D turretTexture;
    Texture2D bulletTexture;
    Matrix3 bodyTransform;
    Matrix3 turretTransform;
    MathClasses::Vector3 turretOffset;
    std::vector<Bullet> bullets;

};

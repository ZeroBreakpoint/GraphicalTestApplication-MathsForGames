# GraphicalTestApplicationMathsForGames(C++ with Raylib and Custom Math Library)

This project is my 2D top-down tank simulation created using **Raylib** for rendering and a custom-built `Vector3` and `Matrix3` (from my CustomDataTypesMathsForGames project) math library for all spatial transformations.  It was developed as part of an assessment at the Academy of Interactive Entertainment (AIE).

## Project Features

### Tank Movement
- Controlled with `W`, `A`, `S`, `D` keys:
  - `W/S` moves the tank forward/backward
  - `A/D` rotates the tank left/right
- Position and orientation managed entirely with `Vector3` and `Matrix3`

### Turret Mechanics
- Independent turret rotation via `Q/E`
- Fully **parented to the tank body** using a **matrix hierarchy**
- Follows tank’s position and rotation while supporting its own rotation

### Bullet System
- Fire a bullet using the `Spacebar`
- Bullets spawn at the end of the turret and travel in its facing direction
- Bullet is **not parented** to the tank or turret once fired
- Implements:
  - Linear motion using `Vector3`
  - Collision detection with screen bounds
  - Box-based collision with a target rectangle

### Custom Math Integration

This game integrates with a custom `MathClasses` namespace, which includes:

#### `Vector3`:
- Fields: `x`, `y`, `z`
- Methods: `Magnitude()`, `Normalise()`, `Dot()`, `Cross()`
- Overloaded operators: `+`, `-`, `*`, `==`, `!=`

#### `Matrix3`:
- Fields: `m1` through `m9` and `axis[3]`
- Methods:
  - `setRotateZ(float angle)`
  - `setTranslate(float x, float y)`
  - `operator*(Matrix3, Vector3)`
- Matrix composition: Used for hierarchical transformations of the tank and turret

---

## Controls

| Key        | Action                       |
|------------|------------------------------|
| W / S      | Move tank forward/backward   |
| A / D      | Rotate tank body             |
| Q / E      | Rotate turret left/right     |
| Spacebar   | Fire a bullet                |

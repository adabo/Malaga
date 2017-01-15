#pragma once
#include "Vector.h"
#include "Colors.h"

class Graphics;

class Entity
{
public:
	Entity();
    Entity( Vector Pos, float Hp, float Velocity,
			bool IsAlive = true, int Width = 0, int Height = 0 );

	virtual bool IsColliding( const Vector &OtherPosition, float Width, float Height ) = 0;
	virtual void DoCollision( float CollisionCost ) = 0;

	virtual void Update( float Dt ) = 0;
	virtual void Draw( Graphics &Gfx ) = 0;

public:

	Vector position;
	float hp,
		  damage,
		  velocity;
	bool  is_alive;
	int	  width, height;
};


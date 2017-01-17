#pragma once
#include "Vector.h"
#include "Colors.h"

class Graphics;

class Entity
{
public:

	/*Entity( Vector Pos, float Hp, float Speed,
	bool IsAlive = true, int Width = 0, int Height = 0 );*/
	// If you can think of any instance where a newly created entity is not alive,
	// I don't think there's a reason to include it as a constructor variable.
	// If you would still prefer to have it in there, it should be the last item in the
	// argument list as it is the least common one that will be changed.
	Entity( const Vector &Pos, const Vector &Heading, int Width = 0,
			int Height = 0, float Speed = 30.f, float HP = 1.f, float Damage = .1f );

	// Usually a good idea to have a virtual destructor for parent class, without it
	// child class destructors don't get called...or at least that's the standard anyway
	virtual ~Entity() {}

	virtual bool IsColliding( const Vector &OtherPosition, float Width, float Height )const = 0;
	virtual void DoCollision( float CollisionCost ) = 0;

	virtual void Update( float Dt ) = 0;
	virtual void Draw( Graphics &Gfx ) = 0;

public:
	Vector position, velocity;
	float hp, damage, speed;
	int	  width, height;
	bool  is_alive = true;
};


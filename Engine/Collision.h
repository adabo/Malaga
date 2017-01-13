#pragma once

#include "Vector.h"


class Collision
{
public:
    Collision();

	virtual bool IsColliding( const Vector &OtherPosition, float Width, float Height )const = 0;
	virtual void DoCollision( float CollisionCost ) = 0;
	
};


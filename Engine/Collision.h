#pragma once

#include "Entity.h"

struct Collision
{
	static bool IsColliding( const Entity &A, const Entity &B );
	static void DoCollision( Entity &A, Entity &B );	
	static bool IsInView( const Entity &A );
};

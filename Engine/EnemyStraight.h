#pragma once

#include "Entity.h"

class EnemyStraight :
	public Entity
{
public:
	EnemyStraight( const Vector &Pos, const Vector &Heading, int Width = 0,
				   int Height = 0, float Speed = 30.f, float HP = 1.f, float Damage = .1f );
	
};


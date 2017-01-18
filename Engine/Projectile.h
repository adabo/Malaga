#pragma once

#include "Entity.h"

class Projectile :public Entity
{
public:
	Projectile( const Vector &Pos, const Vector &Heading, int Width = 0,
				int Height = 0, float Speed = 30.f, float HP = 1.f, float Damage = .1f );


	void Update( float Dt ) override;
	void Draw( Graphics &Gfx ) override;
};


#pragma once

#include "Entity.h"

class Graphics;

class EnemyTrackStatic : public Entity
{
public:
	EnemyTrackStatic( const Vector &Pos, const Vector &Heading, int Width,
					   int Height, float Speed = 30.f, float HP = 1.f,
					   float Damage = .1f, Color C = Colors::Black );

	void Update( float Dt )override;
	void Draw( Graphics &Gfx )override;

	Color color;
};

#include "Projectile.h"
#include "Graphics.h"

Projectile::Projectile( const Vector & Pos, const Vector & Heading, int Width,
						int Height, float Speed, float HP, float Damage )
	:
	Entity( Pos, Heading, Width, Height, Speed, HP, Damage )
{
	velocity = Heading * Speed;
}

void Projectile::Update( float Dt )
{
	position = position + ( velocity * Dt );
}

void Projectile::Draw( Graphics & Gfx )
{
	const Vector previous_position = position - velocity;
	Gfx.DrawLine( previous_position.x, previous_position.y, position.x, position.y, Colors::Red );
}

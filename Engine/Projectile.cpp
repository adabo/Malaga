#include "Projectile.h"
#include "Graphics.h"

Projectile::Projectile( const Vector & Pos, const Vector & Heading, int Width,
						int Height, float Speed, float HP, float Damage )
	:
	Entity( Pos, Heading * Speed, Width, Height, Speed, HP, Damage )
{
}

void Projectile::Update( float Dt )
{
	position = position + ( velocity * Dt );
}

void Projectile::Draw( Graphics & Gfx )
{
	const Vector previous_position = position - (velocity.Normalize() * 10.f);
	Gfx.DrawLine( 
		static_cast<int>(previous_position.x), 
		static_cast<int>(previous_position.y), 
		static_cast<int>(position.x), 
		static_cast<int>(position.y), 
		Colors::Red );
}

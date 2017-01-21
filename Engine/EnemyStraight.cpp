#ifndef FULL_WINTARD
#define FULL_WINTARD
#endif // !FULL_WINTARD

#include "EnemyStraight.h"
#include "Graphics.h"

EnemyStraight::EnemyStraight( const Vector & Pos, const Vector & Heading,
							  int Width, int Height, float Speed, float HP,
							  float Damage, Color C )
	:
	Entity( Pos, Heading * Speed, Width, Height, Speed, HP, Damage ),
	color( C )
{}

void EnemyStraight::Update( float Dt )
{
	position = position + ( velocity * Dt );
	
}

void EnemyStraight::Draw( Graphics & Gfx )
{
	Gfx.DrawRect( 
		static_cast<int>( position.x ),
		static_cast<int>( position.y ), 
		width, height, color );
}

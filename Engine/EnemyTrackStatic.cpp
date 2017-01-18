#include "EnemyTrackStatic.h"
#include "Graphics.h"

EnemyTrackStatic::EnemyTrackStatic( const Vector &Pos, const Vector &Heading,
									  int Width, int Height, float Speed,
									  float HP, float Damage, Color C )
	:
	Entity( Pos, Heading * Speed, Width, Height, Speed, HP, Damage ),
	color( C )
{
}

void EnemyTrackStatic::Update( float Dt)
{
	position = position + ( velocity * Dt );
}

void EnemyTrackStatic::Draw( Graphics &Gfx )
{
	Gfx.DrawRect( position.x, position.y, width, height, color );
}

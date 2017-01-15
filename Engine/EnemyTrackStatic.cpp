#include "EnemyTrackStatic.h"
#include <time.h>
#include <cstdlib>

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
    float frame_step = velocity * Dt;
    x += frame_step;
    y += frame_step;
}

void EnemyTrackStatic::Draw( Graphics &Gfx )
{

}

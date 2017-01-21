#include "EnemyTrackMotion.h"
#include "Graphics.h"

EnemyTrackMotion::EnemyTrackMotion( const Vector &Pos, const Vector &Dir, float Width, float Height, Color C )
	:
	Entity( Pos, Dir, ( int )Width, ( int )Height )
{}

void EnemyTrackMotion::Update( float Dt )
{
	velocity = ( player_pos - position ).Normalize() * speed;
	position = position + ( velocity * Dt );
}

void EnemyTrackMotion::Draw( Graphics & Gfx )
{
	Gfx.DrawRect( 
		static_cast<int>( position.x ),
		static_cast<int>( position.y ),
		width, height, color );
}

void EnemyTrackMotion::SetPlayerPosition( const Vector & PlayerPos )
{
	player_pos = PlayerPos;
}

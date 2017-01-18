#include "EnemyTrackMotion.h"
#include "Graphics.h"

EnemyTrackMotion::EnemyTrackMotion( const Vector &Pos, const Vector &Dir, float Width, float Height, Color C )
	:
	Entity( Pos, Dir, ( int )Width, ( int )Height )
{}

bool EnemyTrackMotion::IsColliding( const Vector & OtherPosition, float Width, float Height ) const
{
	return ( player_pos.x < OtherPosition.x + Width && player_pos.x + width > OtherPosition.x &&
			 player_pos.y < OtherPosition.y + Width && player_pos.y + height > OtherPosition.y );
}

void EnemyTrackMotion::DoCollision( float CollisionCost )
{
	hp -= CollisionCost;
	is_alive = hp > 0.f;
}

void EnemyTrackMotion::Update( float Dt )
{
	const Vector diff = player_pos - position;
	const Vector direction = diff.Normalize() * Dt;

	position = position + ( direction * speed );
}

void EnemyTrackMotion::Draw( Graphics & Gfx )
{
	Gfx.DrawRect( position.x, position.y, width, height, color );
}

void EnemyTrackMotion::SetPlayerPosition( const Vector & PlayerPos )
{
	player_pos = PlayerPos;
}

#include "EnemyTrackMotion.h"
#include "Graphics.h"



EnemyTrackMotion::EnemyTrackMotion( const Vector &Pos, const Vector &Dir, float Width, float Height )
{}

EnemyTrackMotion::EnemyTrackMotion( const Vector & Pos, int Width, int Height )
	:
	Entity( Pos, Width, Height )
{}


EnemyTrackMotion::~EnemyTrackMotion()
{}

bool EnemyTrackMotion::IsColliding( const Vector & OtherPosition, float Width, float Height ) const
{
	return (
		m_position.x < OtherPosition.x + Width && m_position.x + m_width > OtherPosition.x &&
		m_position.y < OtherPosition.y + Width && m_position.y + m_height > OtherPosition.y
		);
}

void EnemyTrackMotion::DoCollision( float CollisionCost )
{
	m_hp -= CollisionCost;
}

void EnemyTrackMotion::Update( float Dt )
{
	const Vector diff = m_player_pos - pos;
	const Vector direction = diff.Normalize() * Dt;

	pos += ( direction * m_speed );
}

void EnemyTrackMotion::Draw( Graphics & Gfx )
{
	Gfx.DrawRect( pos.x, pos.y, width, height, Colors::Blue );
}

void EnemyTrackMotion::SetPlayerPosition( const Vector & PlayerPos )
{
	player_pos = PlayerPos;
}

#include "EnemyHoming.h"
#include "Graphics.h"



EnemyHoming::EnemyHoming()
{}


EnemyHoming::~EnemyHoming()
{}

void EnemyHoming::Update( float Dt )
{
	const Vector diff = m_player_pos - pos;
	const Vector direction = diff.Normalize() * Dt;

	pos += ( direction * m_speed );
}

void EnemyHoming::Draw( Graphics & Gfx )
{
	Gfx.DrawRect( pos.x, pos.y, width, height, Colors::Blue );
}

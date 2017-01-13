#include "Shield.h"
#include <algorithm>


Shield::Shield()
	:
	regen_rate(0.f)
{}


Shield::~Shield()
{}

float Shield::GetHP() const
{
	return m_hp;
}

void Shield::IncreaseHP( float Amount )
{
	m_hp = std::min( 1.f, m_hp + Amount );
}

void Shield::DecreaseHP( float Amount )
{
	m_hp = std::max( 0.f, m_hp - Amount );
}

void Shield::UpdatePosition( const Vector & NewPosition )
{
	m_position = NewPosition;
}

void Shield::Update( float Dt )
{
	const float recip_full_regen_time = 1.f / regen_max_time;
	IncreaseHP( Dt * recip_full_regen_time );
}

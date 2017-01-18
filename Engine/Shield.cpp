#define NOMINMAX
#include "Shield.h"
#include <algorithm>
#include "Graphics.h"

Shield::Shield( float HitPoints, float Radius )
	:
	hp( HitPoints ),
	radius( Radius )
{}

float Shield::GetHP() const
{
	return hp;
}

void Shield::IncreaseHP( float Amount )
{
	hp = std::min( 1.f, hp + Amount );
}

void Shield::DecreaseHP( float Amount )
{
	hp = std::max( 0.f, hp - Amount );
}

void Shield::Update( float Dt )
{
	const float recip_full_regen_time = 1.f / regen_max_time;
	IncreaseHP( Dt * recip_full_regen_time );
}

void Shield::Draw( const Vector &ShipPosition, Graphics & Gfx )
{	
	const unsigned char value_green = static_cast<unsigned char>( 255.f * hp );
	const unsigned char value_red = 255 - value_green;

	Gfx.DrawRectOutline(
		static_cast< int >( ShipPosition.x ),
		static_cast< int >( ShipPosition.y ),
		32,32, Color( value_red, value_green, 0 )
	);
}

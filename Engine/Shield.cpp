#define NOMINMAX
#include "Shield.h"
#include <algorithm>
#include "Amalgum.h"
#include "Graphics.h"

Shield::Shield( float HitPoints )
	:
	hp( HitPoints )
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

void Shield::Update( float Dt, Amalgum &rAmalgum )
{
	hp = rAmalgum.ship.hp;
	IncreaseHP( Dt * ( 1.f / regen_max_time ) );
	rAmalgum.ship.hp = hp;
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

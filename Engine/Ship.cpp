#include "Ship.h"
#include "Amalgum.h"
#include "Graphics.h"

Ship::Ship( const Vector & Pos, const Vector & Heading, int Width, int Height, float Speed, float HP, float Damage )
	:
	Entity( Pos, Heading, Width, Height, Speed, HP, Damage )
{}

void Ship::Update( float Dt )
{
	position = position + ( velocity * Dt);
}

void Ship::ClampToScreenEdges()
{
	position.x = std::min( Amalgum::screen_size.width - ( width + 1 ),   std::max( position.x, 0.f ) );
	position.y = std::min( Amalgum::screen_size.height - ( height + 1 ), std::max( position.y, 0.f ) );
}

void Ship::Draw( Graphics &Gfx )
{
	Gfx.DrawRect( 
		static_cast<int>( position.x ),
		static_cast<int>( position.y ),
		width, height, Colors::Gray );
}


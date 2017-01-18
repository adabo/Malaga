#include "Ship.h"
#include "Graphics.h"

Ship::Ship( const Vector & Pos, const Vector & Heading, int Width, int Height, float Speed, float HP, float Damage )
	:
	Entity( Pos, Heading, Width, Height, Speed, HP, Damage )
{}

void Ship::Update( float Dt )
{
	position = position + velocity;
}

void Ship::ClampToScreenEdges()
{}

void Ship::Draw( Graphics &Gfx )
{}


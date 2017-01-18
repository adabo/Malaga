#include "Ship.h"

Ship::Ship( Vector Pos, bool IsColliding = false )
{}

void Ship::Draw()
{
}

void Ship::Update( float Dt )
{
	if( is_left_pressed || is_right_pressed )
	{
		position.x += speed;
	}
	else if( position.y >= Amalgum::screen_size.width )
	{
		
}

bool Ship::IsColliding()
{
	return false;
}

void Ship::DoInput()
{}

void Ship::ClampToScreenEdges()
{}

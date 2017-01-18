#include "Collision.h"
#include "Amalgum.h"

bool Collision::IsColliding( const Entity & A, const Entity & B )
{
	return(
		A.position.x < B.position.x + B.width  && A.position.x + A.width  > B.position.x &&
		A.position.y < B.position.y + B.height && A.position.y + A.height > B.position.y
		);
}

void Collision::DoCollision( Entity & A, Entity & B )
{
	if( Collision::IsColliding( A, B ) )
	{
		A.hp -= B.damage;
		A.is_alive = A.hp > 0.f;
		B.hp -= A.damage;
		B.is_alive = B.hp > 0.f;
	}
}

bool Collision::IsInView( const Entity & A )
{
	return(
		A.position.x < Amalgum::screen_size.width  && A.position.x + A.width  > 0.f &&
		A.position.y < Amalgum::screen_size.height && A.position.y + A.height > 0.f
		);
}

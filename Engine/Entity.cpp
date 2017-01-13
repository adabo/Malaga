#include "Entity.h"

Entity::Entity()
{}

Entity::Entity( float X, float Y, float Hp, bool IsAlive )
	:
		x( X ),
		y( Y ),
		hp( Hp ),
		is_alive( IsAlive )
{}

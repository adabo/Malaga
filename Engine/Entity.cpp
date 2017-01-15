#include "Entity.h"
#include "Graphics.h"

Entity::Entity()
{}

Entity::Entity( Vector Position, float Hp, float Velocity,
		        bool IsAlive = false, int Width, int Height )
	:
		position( Position ),
		hp( Hp ),
		velocity( Velocity ),
{}

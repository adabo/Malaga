#include "Entity.h"
#include "Graphics.h"

Entity::Entity()
{}

Entity::Entity( Vector Pos, float Hp, bool IsAlive,
		        int Width, int Height )
	:
		pos( Pos ),
		hp( Hp ),
		is_alive( IsAlive )
{}
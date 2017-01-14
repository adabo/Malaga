#include "Entity.h"
#include "Graphics.h"

Entity::Entity()
{}

Entity::Entity( Vector Pos, float Hp, bool IsAlive,
		        int w, int h )
	:
		pos( Pos ),
		hp( Hp ),
		is_alive( IsAlive )
{}

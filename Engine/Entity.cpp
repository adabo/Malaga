#include "Entity.h"
#include "Graphics.h"

Entity::Entity( const Vector &Pos, const Vector &Heading, int Width, int Height,
				float Speed, float HP, float Damage )
	:
	position( Pos ),
	hp( HP ),
	velocity( Heading ),
	width( Width ),
	height( Height ),
	speed( Speed ),
	damage( Damage )
{}

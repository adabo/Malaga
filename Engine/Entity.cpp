#include "Entity.h"

Entity::Entity()
{}

Entity::Entity( float X, float Y, float Hp, bool IsAlive,
		        int w = 0, h = 0 )
	:
		x( X ),
		y( Y ),
		hp( Hp ),
		is_alive( IsAlive )
{}

void Enemy::Update()
{}

void Enemy::Draw()
{}

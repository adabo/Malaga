#pragma once
#include "Entity.h"

class EnemyLastKnownPos : public Entity
{
public:
	EnemyLastKnownPosition();

	void SpawnEnemyLastKnownPosition(Vector &Player);

	void Update( float Dt J);
	void Draw();


public:
	Vector *p_player_position;
};

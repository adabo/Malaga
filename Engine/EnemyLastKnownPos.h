#pragma once
#include "Entity.h"

class EnemyLastKnownPos : public Entity
{
public:
	EnemyLastKnownPos();

	void Update( float Dt J);
	void Draw();

public:
	float velocity;
};

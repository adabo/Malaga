#pragma once

#include "Colors.h"
#include "Vector.h"

struct Amalgum;

class Spawner
{
	struct EnemyConstructorParams
	{
		Vector pos, heading;
		float hp, speed, damage;
		float width, height;
		Color color;
	};
public:
	enum ScreenSide
	{
		TOP, BOTTOM, LEFT, RIGHT
	};

	Spawner( Amalgum &Amalgum );

	void Spawn( float Dt );

private:
	void SpawnEnemyTrackStatic();
	void SpawnEnemyTrackMotion();
	void SpawnEnemyStraight();
	EnemyConstructorParams CreateBaseParams()const;
	ScreenSide PickSide()const;
	Color PickColor()const;


public:
	Amalgum &amalgum;
	float spawn_rate, spawn_rate_tracker = 0.f;

};

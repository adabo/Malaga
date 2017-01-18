#pragma once

struct Amalgum;

class Spawner
{
public:
	enum ScreenSide
	{
		TOP, BOTTOM, LEFT, RIGHT
	};

	Spawner( Amalgum &Amalgum );

	ScreenSide PickSide()const;
	Color PickColor()const;

	void Spawn( float Dt );
	void SpawnEnemyTrackStatic();
	void SpawnEnemyTrackMotion();
	void SpawnEnemyStraight();
	
public:
	Amalgum &amalgum;
	float spawn_rate, spawn_rate_tracker = 0.f;

};

#pragma once

#include <math.h>

struct Amalgum;

class Spawner
{
public:
	enum ScreenSide
	{
		TOP, BOTTOM, LEFT, RIGHT
	};

	enum EnemyOrientation
	{
		VERTICAL, HORIZONTAL
	};

	Spawner( Amalgum &Amalgum );

	void SpawnEnemyHoming();
	void SpawnEnemyLastKnownPosition();
	void SpawnEnemyStraight();

	void SetScreenSide( ScreenSide Side );

public:
	Amalgum &amalgum;
	ScreenSide side;
};

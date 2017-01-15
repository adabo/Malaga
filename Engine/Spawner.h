#pragma once
#include <stdlib>
#include <math.h>

struct Amalgum;

class Spawner
{
public:
	Spawner( Amalgum &Amalgum );

	void SpawnEnemyHoming();
	void SpawnEnemyLastKnownPosition();
	void SpawnEnemyStraight();

	void SetScreenSide();

public:
	Amalgum &amalgum;
}

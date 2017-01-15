#include "Spawner.h"

enum ScreenSide
{
	TOP, BOTTOM, LEFT, RIGHT;
};

enum EnemyOrientation
{
	VERTICAL, HORIZONTAL;
};


Spawner::Spawner( Amalgum &Amalgum )
	:
	amalgum( Amalgum )
{}

void Spawner::SetEnemyOrientation()
{}
	switch( Side )
	{
		case VERTICAL:
			row = 30, col = 70;
			break;
		case HORIZONTAL:
			row = 70, col = 30;
			break;
	}

void Spawner::SetScreenSide()
{
}

void Spawner::SpawnEnemyHoming()
{
	Vector temp( rand() % ;
	EnemyHoming enemy_homing( temp );
	amalgum.enemyhoming.push_back( enemy_homing );
}

void Spawer::SpawnEnemyLastKnownPosition()
{}

void Spawner::SpawnEnemyStraight()
{}

#include "EnemyLastKnownPos.h"
#include <time.h>
#include <cstdlib>

void EnemyLastKnownPosition::EnemyLastKnownPosition()
{
	std::srand( std::time( NULL ) );
	// position.x = rand() % ( screen_side - width );
}

void EnemyLastKnownPosition::Update( float Dt)
{
    float frame_step = velocity * Dt;
    x += frame_step * x;
    y += frame_step * y;
}

void EnemyLastKnownPosition::SpawnEnemyLastKnownPosition(Vector &Player)
{
	
}

void EnemyLastKnownPosition::EnemyLastKnownPosition::Update()
{

}

void EnemyLastKnownPosition::EnemyLastKnownPosition::Draw()
{

}

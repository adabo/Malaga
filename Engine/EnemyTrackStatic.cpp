#include "EnemyLastKnownPos.h"
#include <time.h>
#include <cstdlib>

void EnemyTrackStatic::EnemyTrackStatic()
{
	std::srand( std::time( NULL ) );
	// position.x = rand() % ( screen_side - width );
}

void EnemyTrackStatic::Update( float Dt)
{
    float frame_step = velocity * Dt;
    x += frame_step * x;
    y += frame_step * y;
}

void EnemyTrackStatic::SpawnEnemyTrackStatic(Vector &Player)
{
	
}

void EnemyTrackStatic::EnemyTrackStatic::Update()
{

}

void EnemyTrackStatic::EnemyTrackStatic::Draw()
{

}

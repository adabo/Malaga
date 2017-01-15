#include "Spawner.h"
#include "Amalgum.h"
#include "Random.h"
// TODO: Need to include Amalgum.h here
// TODO: Need to include Random.h here
// Check out Random.h to see what functions are available

Spawner::Spawner( Amalgum &Amalgum )
	:
	amalgum( Amalgum )
{}

// TODO: Function Spawner::SetEnemyOrientation not declared in .h file
// So I commented it out.
//void Spawner::SetEnemyOrientation()
//{
//}
	

void Spawner::SetScreenSide( Spawner::ScreenSide Side )
{
	// TODO: Decide what function Spawner::SetScreenSide is going to do
	int row, col;
	switch( Side )
	{
		case VERTICAL:
			row = 30, col = 70;
			break;
		case HORIZONTAL:
			row = 70, col = 30;
			break;
	}
	side = Side;
}

void Spawner::SpawnEnemyHoming()
{
	// TODO: Use Josh's Random class instead of rand()
	// Random functions are static so you don't have to create a Random 
	// object before calling them
	// Random::GetRandomInt( 0, 100 ) returns a random int from 0 to 99
	// Random::GetRandomFloat(3.9f, 10.39f) returns a random float from 3.9 to 10.39
	/* To make a Vector: 
	Vector randVec(
		Random::GetRandomFloat( 0.f, 800.f ),
		-Random::GetRandomFloat( 0.f, 30.f )
	);
	*/
	// TODO: Generate position, speed and color
	// Don't need to generate direction since the direction will 
	// be calculated each frame
	Vector temp( rand() % ;
	EnemyHoming enemy_homing( temp );
	amalgum.enemyhoming.push_back( enemy_homing );
}

void Spawner::SpawnEnemyLastKnownPosition()
{
	// TODO: Calculate enemy direction, generate position, speed and color
	// Create a EnemyLastKnownPos object using generated and calculated values
	// Add to vector in Amalgum
}

void Spawner::SpawnEnemyStraight()
{
	// TODO: Generate position, direction, speed and color
}

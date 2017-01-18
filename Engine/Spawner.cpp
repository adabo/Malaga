#include "Spawner.h"
#include "Amalgum.h"
#include "EnemyStraight.h"
#include "Random.h"

Spawner::Spawner( Amalgum &Amalgum )
	:
	amalgum( Amalgum ),
	spawn_rate( Amalgum::base_spawn_rate )
{}

// TODO: Function Spawner::SetEnemyOrientation not declared in .h file
// So I commented it out.
//void Spawner::SetEnemyOrientation()
//{
//}

Spawner::ScreenSide Spawner::PickSide() const
{
	const int value = Random::GetRandomInt( 0, 4 );
	ScreenSide side;
	switch( value )
	{
		case 0:
			side = ScreenSide::TOP;
			break;
		case 1:
			side = ScreenSide::RIGHT;
			break;
		case 2:
			side = ScreenSide::BOTTOM;
			break;
		case 3:
			side = ScreenSide::LEFT;
			break;
	}
	return side;
}

Color Spawner::PickColor() const
{
	// Set to Cyan to test if 0 to 5 includes 5, if any Cyan show up, then change to 0,4
	Color color = Colors::Cyan;
	switch( Random::GetRandomInt( 0, 5 ) )
	{
		case 0:
			color = Colors::Red;
			break;
		case 1:
			color = Colors::Green;
			break;
		case 2:
			color = Colors::Blue;
			break;
		case 3:
			color = Colors::Magenta;
			break;
		case 4:
			color = Colors::Orange;
			break;
	}
	return color;
}

void Spawner::Spawn( float Dt )
{
	const int difficulty = amalgum.level.GetDifficulty();
	spawn_rate_tracker += Dt;

	if( spawn_rate_tracker < spawn_rate ) return;

	spawn_rate_tracker = 0.f;
	switch( difficulty )
	{
		case 0:			
			SpawnEnemyStraight();
			break;
		case 1:
			SpawnEnemyTrackStatic();
			break;
		case 2:
			SpawnEnemyTrackMotion();
			break;
		case 3:
			SpawnEnemyStraight();
			SpawnEnemyTrackStatic();
			break;
		case 4:
			SpawnEnemyStraight();
			SpawnEnemyTrackMotion();
			break;
		case 5:
			SpawnEnemyTrackStatic();
			SpawnEnemyTrackMotion();
			break;
		case 6:
			SpawnEnemyStraight();
			SpawnEnemyTrackStatic();
			SpawnEnemyTrackMotion();
			break;
		case 7:
			SpawnEnemyStraight();
			SpawnEnemyTrackStatic();
			SpawnEnemyTrackMotion();
			break;
		case 8:
			SpawnEnemyStraight();
			SpawnEnemyTrackStatic();
			SpawnEnemyTrackMotion();
			break;
		case 9:
			SpawnEnemyStraight();
			SpawnEnemyTrackStatic();
			SpawnEnemyTrackMotion();
			break;
	}
}

void Spawner::SpawnEnemyTrackMotion()
{
	const ScreenSide side = PickSide();
	int width = 0, height = 0;
	Vector position, heading;
	if( side == TOP || side == BOTTOM )
	{
		width = 70;
		height = 30;
		position.x = Random::GetRandomFloat( 0.f, static_cast<float>( Graphics::ScreenWidth - width ) );
		if( side == TOP )
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
		}
		else
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
		}
	}
	else
	{
		width = 30;
		height = 70;
		if( side == LEFT )
		{
			position.x = 0.f;
		}
		else
		{
			position.x = static_cast< float >( Graphics::ScreenWidth - width );
		}
		position.y = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenHeight - height ) );
	}
	const float speed = 60.f * static_cast<float>( amalgum.level.GetDifficulty() );
	const float hp = 1.f;

	heading = ( amalgum.ship.position - position ).Normalize();
	amalgum.enemy_straight_list.push_back(
		EnemyStraight( position, heading, width, height, speed, hp, .25f, PickColor() ) );
}

void Spawner::SpawnEnemyTrackStatic()
{
	const ScreenSide side = PickSide();
	int width = 0, height = 0;
	Vector position, heading;
	if( side == TOP || side == BOTTOM )
	{
		width = 70;
		height = 30;
		position.x = Random::GetRandomFloat( 0.f, static_cast<float>( Graphics::ScreenWidth - width ) );
		if( side == TOP )
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
		}
		else
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
		}
	}
	else
	{
		width = 30;
		height = 70;
		if( side == LEFT )
		{
			position.x = 0.f;
		}
		else
		{
			position.x = static_cast< float >( Graphics::ScreenWidth - width );
		}
		position.y = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenHeight - height ) );
	}
	const float speed = 60.f * static_cast<float>( amalgum.level.GetDifficulty() );
	const float hp = 1.f;

	heading = ( amalgum.ship.position - position ).Normalize();
	amalgum.enemy_straight_list.push_back( 
		EnemyStraight( position, heading, width, height, speed, hp, .25f, PickColor() ) );
}

void Spawner::SpawnEnemyStraight()
{
	const ScreenSide side = PickSide();
	int width = 0, height = 0;
	Vector position, heading;
	if( side == TOP || side == BOTTOM )
	{
		width = 70;
		height = 30;
		position.x = Random::GetRandomFloat( 0.f, static_cast<float>( Graphics::ScreenWidth - width ) );
		heading.x = 0.f;
		if( side == TOP )
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
			heading.y = 1.f;
		}
		else
		{
			position.y = side == TOP ? 0.f : static_cast< float >( Graphics::ScreenHeight - height );
			heading.y = -1.f;
		}
	}
	else
	{
		width = 30;
		height = 70;
		if( side == LEFT )
		{
			position.x = 0.f;
			heading.x = -1.f;
		}
		else
		{
			position.x = static_cast< float >( Graphics::ScreenWidth - width );
			heading.x = 1.f;
		}
		position.y = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenHeight - height ) );		
	}
	const float speed = 60.f * static_cast<float>( amalgum.level.GetDifficulty() );
	const float hp = 1.f;

	amalgum.enemy_straight_list.push_back( EnemyStraight( position, heading, width, height, speed, hp, .25f, PickColor() ) );
}

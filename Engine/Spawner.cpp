#include "Spawner.h"
#include "Amalgum.h"
#include "EnemyStraight.h"
#include "Random.h"

Spawner::Spawner( Amalgum &Amalgum )
	:
	amalgum( Amalgum ),
	spawn_rate( Amalgum::base_spawn_rate )
{}

Spawner::ScreenSide Spawner::PickSide() const
{
	const int value = Random::GetRandomIntInRange( 0, 4 );
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
	Color color = Colors::Cyan;
	switch( Random::GetRandomIntInRange( 0, 5 ) )
	{
		case 0:
			// color = Colors::Red;
			color = Colors::EnemyBrown;
			break;
		case 1:
			color = Colors::Green;
			break;
		case 2:
			// color = Colors::Blue;
			color = Colors::EnemyPink;
			break;
		case 3:
			// color = Colors::Magenta;
			color = Colors::EnemyGrey;
			break;
		case 4:
			// color = Colors::Orange;
			color = Colors::EnemyOrange;
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
	EnemyConstructorParams params = CreateBaseParams();

	params.heading = ( amalgum.ship.position - params.pos ).Normalize();
	amalgum.enemy_straight_list.push_back(
		EnemyStraight(
			params.pos,
			params.heading,
			params.width,
			params.height,
			params.speed,
			params.hp,
			params.damage,
			params.color ) );
}

void Spawner::SpawnEnemyTrackStatic()
{
	EnemyConstructorParams params = CreateBaseParams();

	params.heading = ( amalgum.ship.position - params.pos ).Normalize();
	amalgum.enemy_straight_list.push_back( 
		EnemyStraight( 
			params.pos, 
			params.heading, 
			params.width, 
			params.height, 
			params.speed, 
			params.hp, 
			params.damage, 
			params.color ) );
}

void Spawner::SpawnEnemyStraight()
{
	const EnemyConstructorParams params = CreateBaseParams();

	amalgum.enemy_straight_list.push_back( 
		EnemyStraight(
			params.pos,
			params.heading,
			params.width,
			params.height,
			params.speed,
			params.hp,
			params.damage,
			params.color ) );
}

Spawner::EnemyConstructorParams Spawner::CreateBaseParams() const
{
	const ScreenSide side = PickSide();
	EnemyConstructorParams params{};
	
	if( side == TOP || side == BOTTOM )
	{
		params.width = 70.f;
		params.height = 30.f;
		params.pos.x = Random::GetRandomFloat( 0.f, static_cast<float>( Graphics::ScreenWidth - params.width ) );
		params.heading.x = 0.f;
		if( side == TOP )
		{
			params.pos.y = 0.f;
			params.heading.y = 1.f;
		}
		else
		{
			params.pos.y = static_cast< float >( Graphics::ScreenHeight - params.height );
			params.heading.y = -1.f;
		}
	}
	else
	{
		params.width = 30;
		params.height = 70;
		params.pos.y = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenHeight - params.height ) );
		params.heading.y = 0.f;
		if( side == LEFT )
		{
			params.pos.x = 0.f;
			params.heading.x = 1.f;
		}
		else
		{
			params.pos.x = static_cast< float >( Graphics::ScreenWidth - params.width );
			params.heading.x = -1.f;
		}
	}
	params.speed = 60.f * static_cast<float>( amalgum.level.GetDifficulty() + 1 );
	params.hp = 1.f;
	params.color = PickColor();
	return params;
}

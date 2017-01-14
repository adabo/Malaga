#pragma once

#include "EnemyHoming.h"
#include "Level.h"
#include "Player.h"
#include "StarField.h"
#include "Timer.h"
#include "Weapon.h"

struct Amalgum
{
	Amalgum( Keyboard &Kbd );

	// TODO:
	// EnemyStraight m_enemy_straight;
	// EnemyLastKnown m_enemy_last_known;
	EnemyHoming enemy_homing;
	Level level;

	Player player;
	Timer timer;

	StarField stars;	
};


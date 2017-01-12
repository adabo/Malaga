#pragma once

#include "EnemyHoming.h"
#include "Level.h"
#include "Player.h"
#include "Timer.h"
#include "Weapon.h"

struct Amalgum
{
	Amalgum( Keyboard &Kbd );
	// TODO:
	// EnemyStraight m_enemy_straight;
	// EnemyLastKnown m_enemy_last_known;
	EnemyHoming m_enemy_homing;
	Level m_level;

	Player m_player;
	Timer m_timer;

};


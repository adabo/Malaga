#pragma once

#include "EnemyHoming.h"
#include "Graphics.h"
#include "Level.h"
#include "Player.h"
#include "StarField.h"
#include "Timer.h"
#include "Weapon.h"

struct Amalgum
{
	Amalgum( Keyboard &Kbd );

	// Screen size cached in SizeF object
	static constexpr SizeF screen_size = { ( float )Graphics::ScreenWidth, ( float )Graphics::ScreenHeight };

	// TODO:
	// EnemyStraight m_enemy_straight;
	// EnemyLastKnown m_enemy_last_known;
	EnemyHoming enemy_homing;
	Level level;

	Player player;
	Timer timer;

	StarField stars;	
};


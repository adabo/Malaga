#pragma once

#include <vector>
#include "EnemyStraight.h"
#include "EnemyTrackStatic.h"
#include "EnemyTrackMotion.h"
#include "Graphics.h"
#include "Level.h"
#include "Player.h"
#include "StarField.h"
#include "Timer.h"
#include "Weapon.h"
#include "Utilities.h"

struct Amalgum
{
	Amalgum( Keyboard &Kbd );

	// Screen size cached in SizeF object
	static constexpr SizeF screen_size = { ( float )Graphics::ScreenWidth, ( float )Graphics::ScreenHeight };

	std::vector<EnemyStraight> enemy_straight_list;
	std::vector<EnemyTrackStatic> enemy_last_known_list;
	std::vector<EnemyTrackMotion> enemy_homing_list;
	Level level;

	Ship ship;
	Player player;
	Timer timer;

	StarField stars;	
};


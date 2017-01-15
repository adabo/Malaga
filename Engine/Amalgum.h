#pragma once

#include <vector>
#include "EnemyHoming.h"
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

	// TODO:
	std::vector<EnemyStraight> enemy_straight_list;
	std::vector<EnemyLastKnown> enemy_last_known_list;
	std::vector<EnemyHoming> enemy_homing_list;
	Level level;

	Player player;
	Timer timer;

	StarField stars;	
};


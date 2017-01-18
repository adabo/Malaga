#pragma once

#include <vector>
#include "EnemyStraight.h"
#include "EnemyTrackStatic.h"
#include "EnemyTrackMotion.h"
#include "Graphics.h"
#include "Level.h"
#include "Player.h"
#include "Projectile.h"
#include "Shield.h"
#include "Ship.h"
#include "StarField.h"
#include "Timer.h"
#include "Weapon.h"
#include "Utilities.h"
#include "View.h"

class Keybaord;
class Mouse;

struct Amalgum
{
	Amalgum( Keyboard &Kbd, Mouse &Mse );

	// Screen size cached in SizeF object
	static SizeF screen_size;

	std::vector<EnemyStraight> enemy_straight_list;
	std::vector<EnemyTrackStatic> enemy_last_known_list;
	std::vector<EnemyTrackMotion> enemy_homing_list;
	std::vector<Projectile> projectile_list;
	
	Timer timer;
	Level level;
	Ship ship;
	Shield shield;
	Player player;
	StarField stars;
	View view;
	Weapon weapon;

	constexpr unsigned max_bullets = 10u;

};


#pragma once

#include "Ship.h"


class Keyboard;
class Amalgum;


class Player
{
public:
	Player( Keyboard &M, Amalgum &rAmalgum );
	void Update(float Dt);
	void Draw( class Graphics &Gfx );
private:
	Keyboard &keyboard;
	Amalgum &amalgum;
	Ship ship;
	constexpr static float fire_rate = .1f;
	float fire_rate_tracker = 0.f;
};


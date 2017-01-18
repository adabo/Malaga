#pragma once

class Amalgum;
class Keyboard;
class Mouse;
class Ship;

class Player
{
public:
	Player( Keyboard &M, Mouse &Mse, Amalgum &rAmalgum );
	void Update(float Dt);
	void Draw( class Graphics &Gfx );

	Keyboard &keyboard;
	Mouse &mouse;
	Amalgum &amalgum;
	Ship &ship;
	
	constexpr static float fire_rate = .1f;
	float fire_rate_tracker = 0.f;
};


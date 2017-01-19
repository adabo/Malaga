#pragma once

struct Amalgum;
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
	
};


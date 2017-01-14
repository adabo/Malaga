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
	Ship ship;
	Amalgum &amalgum;
};


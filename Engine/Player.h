#pragma once

#include "Ship.h"


class Keyboard;
class Amalgum;


class Player
{
public:
	Player( Keyboard &M, Amalgum &rAmalgum );
	void Update(float Dt);
private:
	Keyboard &m_keyboard;
	Ship m_ship;
	Amalgum &m_amalgum;
};


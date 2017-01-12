#pragma once

#include "Ship.h"


class Keyboard;

class Player
{
public:
	Player( Keyboard &M );
	void Update();
private:
	Keyboard &m_keyboard;
	Ship m_ship;
};


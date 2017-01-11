#pragma once

#include "Ship.h"


class Mouse;

class Player
{
public:
	Player( Mouse &M );
	void Update();
private:
	Mouse &m_mouse;
	Ship m_ship;
};


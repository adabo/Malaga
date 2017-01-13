#pragma once

#include "Player.h"
#include "EnemyHoming.h"

class Graphics;

class Draw
{
public:
    Draw();
	void Render( Graphics &Gfx );
private:
	// Need UI elements that represent the HUD.
	float m_shield_level;
	float m_hit_miss_ratio;

};


#pragma once


class Graphics;
class Amalgum;

class Draw
{
public:
    Draw( Amalgum &Amal);
	void Render( Graphics &Gfx );
private:
	Amalgum &m_amalgum;
	// Need UI elements that represent the HUD.
	float m_shield_level;
	float m_hit_miss_ratio;

};


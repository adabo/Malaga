#pragma once


class Graphics;
class Amalgum;

class Draw
{
public:
    Draw( Amalgum &Amal);
	void Render( Graphics &Gfx );
private:
	Amalgum &amalgum;
	// Need UI elements that represent the HUD.
	float shield_level;
	float hit_miss_ratio;

};


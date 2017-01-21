#pragma once


class Graphics;
struct  Amalgum;

class View
{
public:
	View( Amalgum &Amal);
	void Render( Graphics &Gfx );
private:
	Amalgum &amalgum;
	// Need UI elements that represent the HUD.
	float shield_level;
	float hit_miss_ratio;

};


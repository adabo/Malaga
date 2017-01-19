#pragma once

#include "Vector.h"

struct Amalgum;
class Graphics;

class Shield
{
public:
	Shield( float HitPoints );
	float GetHP()const;

	void IncreaseHP( float Amount );
	void DecreaseHP( float Amount );
	
	void Update( float Dt, Amalgum &rAmalgum );
	void Draw( const Vector &ShipPsition, Graphics &Gfx );

public:
	// Full shields in 30 seconds from 0.01
	static constexpr float regen_max_time = 30.f;
	float hp;
};


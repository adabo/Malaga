#pragma once

#include "Vector.h"

class Graphics;

class Shield
{
public:
	Shield( float HitPoints, float Radius );
	float GetHP()const;

	void IncreaseHP( float Amount );
	void DecreaseHP( float Amount );
	
	void Update( float Dt );	
	void Draw( const Vector &ShipPsition, Graphics &Gfx );

private:

	// Full shields in 5 seconds
	static constexpr float regen_max_time = 5.f;
	float hp;
	float radius = 50.f;
};


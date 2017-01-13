#pragma once

#include "Vector.h"

class Graphics;

class Shield
{
public:
	Shield();
	~Shield();

	float GetHP()const;

	void IncreaseHP( float Amount );
	void DecreaseHP( float Amount );

	void UpdatePosition( const Vector &NewPosition );
	
	void Update( float Dt );	
	void Draw( Graphics &Gfx );

private:
	Vector m_position;

	// Full shields in 5 seconds
	static constexpr float regen_max_time = 5.f;
	float m_hp;
};


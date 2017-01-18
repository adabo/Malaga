#pragma once

#include <vector>
#include "Vector.h"
#include <random>

class StarField
{
public:
	struct Star
	{
		Vector m_pos = { 0.f, 0.f };
		float m_speed = 0.f;
	};
	StarField();
	~StarField() = default;
	
	void Update( float Dt );
	void Draw( class Graphics &Gfx )const;
private:
	static constexpr unsigned m_star_count = 1250;
	std::vector<Star> m_stars;
};


#pragma once

#include <vector>
#include "Vector.h"
#include <random>

class StarField
{
public:
	struct Star
	{
		Vector pos = { 0.f, 0.f };
		float speed = 0.f;
	};
	StarField();
	~StarField() = default;
	
	void Update( float Dt );
	void Draw( class Graphics &Gfx )const;
private:
	static constexpr unsigned star_count = 1250;
	std::vector<Star> stars;
};


#pragma once

#include <random>

class Random
{
public:
	Random();
	static int GetRandomInt(int MinVal, int MaxVal);
	static float GetRandomFloat( float MinVal, float MaxVal );

private:
	static std::mt19937 rng;
};


#pragma once

class Weapon
{
public:
	enum WeaponType
	{
		SINGLE, DOUBLE, TRIPLE, QUAD
	};

	Weapon();
	void Upgrade();
	void Update( float Dt );
	bool CanFire();
public:
	WeaponType type = SINGLE;
	constexpr static float fire_rate = .1f;
	float fire_rate_tracker = 0.f;
	
};

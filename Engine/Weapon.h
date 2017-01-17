#pragma once

class Weapon
{
	enum WeaponType
	{
		SINGLE, DOUBLE, TRIPLE, QUAD
	};

public:
	Weapon();

	void Upgrade()
	{
		switch (type)
		{
		case SINGLE:
			type = DOUBLE;
			break;
		case DOUBLE:
			type = TRIPLE;
			break;
		case TRIPLE:
			type = QUAD;
			break;
		}
	}
public:
	WeaponType type = SINGLE;
};

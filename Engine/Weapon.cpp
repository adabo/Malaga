#include "Weapon.h"

Weapon::Weapon()
{}

void Weapon::Upgrade()
{
	switch( type )
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

void Weapon::Update( float Dt )
{
	fire_rate_tracker += Dt;
}

bool Weapon::CanFire() 
{
	if( fire_rate_tracker >= fire_rate )
	{
		// Reset fire rate tracker
		fire_rate_tracker = 0.f;

		return true;
	}

	return false;
}

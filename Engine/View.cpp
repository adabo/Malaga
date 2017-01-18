#include "View.h"
#include "Amalgum.h"

View::View( Amalgum &Amal )
	:
	amalgum( Amal )
{}

void View::Render( Graphics & Gfx )
{
	// Draw background
	amalgum.stars.Draw( Gfx );

	// Draw projectiles
	for( auto &projectile : amalgum.projectile_list )
	{
		projectile.Draw( Gfx );
	}

	// Draw ship and shield
	amalgum.player.Draw( Gfx );

	// Draw motion tracking enemies
	for( auto &enemy : amalgum.enemy_homing_list )
	{
		enemy.Draw( Gfx );
	}

	// Draw static tracking enemies
	for( auto &enemy : amalgum.enemy_last_known_list )
	{
		enemy.Draw( Gfx );
	}

	// Draw kamakaze enemies
	for( auto &enemy : amalgum.enemy_straight_list )
	{
		enemy.Draw( Gfx );
	}
}

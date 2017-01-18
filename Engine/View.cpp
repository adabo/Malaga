#include "View.h"
#include "Amalgum.h"

View::View( Amalgum &Amal )
	:
	amalgum( Amal )
{}

void View::Render( Graphics & Gfx )
{
	amalgum.stars.Draw( Gfx );
	amalgum.player.Draw( Gfx );

	for( auto &projectile : amalgum.projectile_list )
	{
		projectile.Draw( Gfx );
	}
	for( auto &enemy : amalgum.enemy_homing_list )
	{
		enemy.Draw( Gfx );
	}
	for( auto &enemy : amalgum.enemy_last_known_list )
	{
		enemy.Draw( Gfx );
	}
	for( auto &enemy : amalgum.enemy_straight_list )
	{
		enemy.Draw( Gfx );
	}
}

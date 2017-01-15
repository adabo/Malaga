#include "Draw.h"
#include "Amalgum.h"

Draw::Draw( Amalgum &Amal )
	:
	amalgum( Amal )
{}

void Draw::Render( Graphics & Gfx )
{
	amalgum.stars.Draw( Gfx );
	amalgum.player.Draw( Gfx );

	for( auto &projectile : amalgum.projectiles )
	{
		projectile.Draw( Gfx );
	}
}

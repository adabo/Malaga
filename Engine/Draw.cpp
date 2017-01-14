#include "Draw.h"
#include "Amalgum.h"

Draw::Draw( Amalgum &Amal )
	:
	m_amalgum( Amal )
{}

void Draw::Render( Graphics & Gfx )
{
	m_amalgum.m_stars.Draw( Gfx );
	m_amalgum.m_player.Draw( Gfx );

	for( auto &projectile : m_amalgum.m_projectiles )
	{
		projectile.Draw( Gfx );
	}
}

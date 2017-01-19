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

	const TextFormat format( TextFormat::WhichFont::FIXEDSYS, Colors::Green );
	// Display the current level
	Gfx.DrawText( 0, 100, Text( amalgum.text_level ).Append( amalgum.level.GetDifficulty() ), format );
	
	// Display the current shield percentage
	Gfx.DrawText( 0, 130, Text( amalgum.text_shield ).Append( amalgum.shield.hp * 100.f ).Append( Text( "%" ) ), format );

	// Display the player's score
	Gfx.DrawText( 0, 160, Text( amalgum.text_score ).Append(0), format );
}

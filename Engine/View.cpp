#ifndef FULL_WINTARD
#define FULL_WINTARD
#endif // !FULL_WINTAR

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

	const TextFormat format( TextFormat::WhichFont::FIXEDSYS_SMALL, Colors::Green );

	const int base_y = 100;
	const int row_padding = 3;
	// Display the current level
	Gfx.DrawText( 0, base_y, Text( amalgum.text_level ).Append( amalgum.level.GetDifficulty() ), format );
	
	// Display the current shield percentage
	const int second_row = base_y + format.font->char_height + row_padding;
	Gfx.DrawText( 0, second_row, Text( amalgum.text_shield ).Append( amalgum.shield.hp * 100.f ).Append( Text( "%" ) ), format );

	// Display the player's score
	const int third_row = second_row + format.font->char_height + row_padding;
	Gfx.DrawText( 0, third_row, Text( amalgum.text_score ).Append(0), format );
}

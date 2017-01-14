/******************************************************************************************
*    Chili DirectX Framework Version 16.07.20                                              *
*    Game.cpp                                                                              *
*    Copyright 2016 PlanetChili.net <http://www.planetchili.net>                           *
*                                                                                          *
*    This file is part of The Chili DirectX Framework.                                     *
*                                                                                          *
*    The Chili DirectX Framework is free software: you can redistribute it and/or modify   *
*    it under the terms of the GNU General Public License as published by                  *
*    the Free Software Foundation, either version 3 of the License, or                     *
*    (at your option) any later version.                                                   *
*                                                                                          *
*    The Chili DirectX Framework is distributed in the hope that it will be useful,        *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                        *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         *
*    GNU General Public License for more details.                                          *
*                                                                                          *
*    You should have received a copy of the GNU General Public License                     *
*    along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Utilities.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	amalgum( wnd.kbd ),
	draw( amalgum )
{
	for( int i = 0; i < max_bullets; ++i )
	{
		bullet_pos[ i ] = { 0.f, 0.f };
		bullet_vel[ i ] = { 0.f, 0.f };
	}
}

void Game::Go()
{
	frame_time = amalgum.timer.Reset();

	UpdateModel();
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// Helpful vars for checking if ship is on/near edges	
	//const SizeF bounds = amalgum.screen_size - ship_size - SizeF( 1.f, 1.f );

	// Clamp the ship to the edges
	ship_pos = ClampToScreen( ship_pos, ship_size );	

	// Update bullet movement
	for( unsigned int i = 0; i < bullet_count; ++i )
	{
		// Update bullet positions
		bullet_pos[ i ] = bullet_pos[ i ] + ( bullet_vel[ i ] * bullet_speed );

		// Check if bullet off screen
		if( !IsInView( bullet_pos[ i ], bullet_size ) )
		{
			ShiftBulletArrays( i );
		}
	}
	
	// Update ship movement
	amalgum.player.Update( frame_time );
	// Move clockwise
	/*if( wnd.kbd.KeyIsPressed( VK_LEFT ) || wnd.kbd.KeyIsPressed( 'A' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x < bounds.width )
		{
			ship_pos.x += ship_speed;
		}
		else if( ship_pos.y >= bounds.height && ship_pos.x > 0.f )
		{
			ship_pos.x -= ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y > 0.f )
			{
				ship_pos.y -= ship_speed;
			}
			else if( ship_pos.x >= bounds.width && ship_pos.y < bounds.height )
			{
				ship_pos.y += ship_speed;
			}
		}
	}*/

	// Move counter clockwise
	/*if( wnd.kbd.KeyIsPressed( VK_RIGHT ) || wnd.kbd.KeyIsPressed( 'D' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x > 0.f )
		{
			ship_pos.x -= ship_speed;
		}
		else if( ship_pos.y >= bounds.height && ship_pos.x < bounds.width )
		{
			ship_pos.x += ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y < bounds.height )
			{
				ship_pos.y += ship_speed;
			}
			else if( ship_pos.x >= bounds.width && ship_pos.y > 0.f )
			{
				ship_pos.y -= ship_speed;
			}
		}
	}*/

	// Fire bullet
	/*if( wnd.kbd.KeyIsPressed( VK_SPACE ) )
	{
		if( fire_rate_tracker >= fire_rate )
		{
			if( bullet_count < max_bullets )
			{
				// Reset fire rate tracker
				fire_rate_tracker = 0.f;

				// Helpful var to determine ships center for bullet spawning
				const SizeF ship_half_size = ship_size * .5f;

				// Set bullet to ship center
				const Vector ship_center = ( ship_pos + ship_half_size );
				bullet_pos[ bullet_count ] = ship_center;

				// Determine travel direction of bullet
				const auto half_screen = screen_size * .5f;
				bullet_vel[ bullet_count ] = ( half_screen - ship_center ).GetNormal();

				// Increase bullet count
				++bullet_count;
			}
		}
	}*/
}

Vector Game::ClampToScreen( const Vector & Pos, const SizeF & Size )
{
	return Vector(
		std::max( 0.f, std::min( Pos.x, amalgum.screen_size.width - Size.width ) ),
		std::max( 0.f, std::min( Pos.y, amalgum.screen_size.height - Size.height ) )
	);
}

bool Game::IsInView( const Vector & Pos, const SizeF & Size )
{
	return (
		( Pos.x + Size.width >= 0.f && Pos.x <  amalgum.screen_size.width ) &&
		( Pos.y + Size.height >= 0.f && Pos.y < amalgum.screen_size.height ) );
}

void Game::ShiftBulletArrays(unsigned int Idx)
{
	for( unsigned int j = Idx + 1; j < bullet_count; ++j )
	{
		const int k = j - 1;
		std::swap( bullet_pos[ j ], bullet_pos[ k ] );
		std::swap( bullet_vel[ j ], bullet_vel[ k ] );
	}
	--bullet_count;
}

void Game::ComposeFrame()
{	
	{ // Draw bullets
		for( int i = 0; i < bullet_count; ++i )
		{
			const int x = ( int )bullet_pos[ i ].x;
			const int y = ( int )bullet_pos[ i ].y;
			const int w = ( int )bullet_size.width;
			gfx.DrawRect( x, y, w, w, Colors::Cyan );
		}
	}
}

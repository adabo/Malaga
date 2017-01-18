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
#include "Collision.h"
#include "Game.h"
#include "Reaper.h"
#include "Utilities.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	amalgum( wnd.kbd, wnd.mouse )
{}

void Game::Go()
{
	UpdateModel();
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
#if !defined(_DEBUG)
	const float frame_time = amalgum.timer.Reset();
#else
	const float frame_time = 1.f / 60.f;
#endif
	// Update star field background
	amalgum.stars.Update( frame_time );

	// Clamp the ship to the edges
	amalgum.ship.ClampToScreenEdges();
	
	// Update bullet movement
	for( unsigned int i = 0; i < amalgum.projectile_list.size(); ++i )
	{
		// Update bullet positions
		amalgum.projectile_list[ i ].Update( frame_time );
	}
	
	// Handle user input
	amalgum.player.Update( frame_time );

	// Update ship movement
	amalgum.ship.Update( frame_time );

	// Update fire rate tracker or bullet spawn timer
	amalgum.weapon.Update( frame_time );

	// Check for and handle collisions
	HandleCollisions();

	// Remove dead entities from entity vectors
	ClearDeadEntities();
}

void Game::HandleCollisions()
{
	for( Projectile &proj : amalgum.projectile_list )
	{
		// Check is alive and if bullet off screen 
		proj.is_alive = proj.is_alive && Collision::IsInView( proj );

		for( auto& enemy : amalgum.enemy_homing_list )
		{
			Collision::DoCollision( proj, enemy );
		}
		for( auto& enemy : amalgum.enemy_last_known_list )
		{
			Collision::DoCollision( proj, enemy );
		}
		for( auto& enemy : amalgum.enemy_straight_list )
		{
			Collision::DoCollision( proj, enemy );
		}
	}

	for( auto &enemy : amalgum.enemy_homing_list )
	{
		// If enemy is heading in a direction and is offscreen on the side
		// they were heading, then they need to die.
		//
		// For instance, enemy started on right side of screen and heading left.
		// If they are off screen on the right but heading left, then they can
		// still live, but if they are heading left and are off screen on the 
		// left, then they die.
		const bool enemy_offscreen = !Collision::IsInView( enemy );
		enemy.is_alive = (
			( ( enemy.velocity.x > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.x < 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y < 0.f ) && enemy_offscreen ) );

		Collision::DoCollision( amalgum.ship, enemy );
	}
	for( auto &enemy : amalgum.enemy_last_known_list )
	{
		const bool enemy_offscreen = !Collision::IsInView( enemy );
		enemy.is_alive = (
			( ( enemy.velocity.x > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.x < 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y < 0.f ) && enemy_offscreen ) );

		Collision::DoCollision( amalgum.ship, enemy );
	}
	for( auto &enemy : amalgum.enemy_straight_list )
	{
		const bool enemy_offscreen = !Collision::IsInView( enemy );
		enemy.is_alive = (
			( ( enemy.velocity.x > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.x < 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y > 0.f ) && enemy_offscreen ) ||
			( ( enemy.velocity.y < 0.f ) && enemy_offscreen ) );

		Collision::DoCollision( amalgum.ship, enemy );
	}
}

void Game::ClearDeadEntities()
{
	Reaper::ClaimDead( amalgum.projectile_list );
	Reaper::ClaimDead( amalgum.enemy_homing_list );
	Reaper::ClaimDead( amalgum.enemy_last_known_list );
	Reaper::ClaimDead( amalgum.enemy_straight_list );
}

void Game::ComposeFrame()
{	
	amalgum.view.Render( gfx );
}

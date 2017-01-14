#include "Player.h"
#include "Amalgum.h"
#include "ChiliWin.h"
#include "Keyboard.h"
#include "Graphics.h"

Player::Player( Keyboard & Kbd, Amalgum &rAmalgum )
	:
	keyboard( Kbd ),
	amalgum( rAmalgum )
{}

void Player::Update( float Dt )
{
	// Helpful vars for checking if ship is on/near edges
	const float screen_width = ( float )Graphics::ScreenWidth;
	const float screen_height = ( float )Graphics::ScreenHeight;
	const float right_bounds = screen_width - 1.f - ship_size;
	const float lower_bounds = screen_height - 1.f - ship_size;

	Vector ship_pos = ship.GetPos();
	Vector ship_direction{};

	// Move clockwise
	if( keyboard.KeyIsPressed( VK_LEFT ) || keyboard.KeyIsPressed( 'A' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x < right_bounds )
		{
			ship_direction = { 1.f, 0.f };
			//m_ship.MoveRight();
			//ship_pos.x += ship_speed;
		}
		else if( ship_pos.y >= lower_bounds && ship_pos.x > 0.f )
		{
			ship_direction = { -1.f, 0.f };
			//m_ship.MoveLeft();
			//ship_pos.x -= ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y > 0.f )
			{
				ship_direction = { 0.f, -1.f };
				//m_ship.MoveUp();
				//ship_pos.y -= ship_speed;
			}
			else if( ship_pos.x >= right_bounds && ship_pos.y < lower_bounds )
			{
				ship_direction = { 0.f, 1.f };
				//m_ship.MoveDown();
				//ship_pos.y += ship_speed;
			}
		}
	}

	// Move counter clockwise
	else if( keyboard.KeyIsPressed( VK_RIGHT ) || keyboard.KeyIsPressed( 'D' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x > 0.f )
		{
			ship_direction = { -1.f, 0.f };
			//m_ship.MoveLeft();
			//ship_pos.x -= ship_speed;
		}
		else if( ship_pos.y >= lower_bounds && ship_pos.x < right_bounds )
		{
			ship_direction = { 1.f, 0.f };
			//m_ship.MoveRight();
			//ship_pos.x += ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y < lower_bounds )
			{
				ship_direction = { 0.f, 1.f };
				//m_ship.MoveDown();
				//ship_pos.y += ship_speed;
			}
			else if( ship_pos.x >= right_bounds && ship_pos.y > 0.f )
			{
				ship_direction = { 0.f, -1.f };
				//m_ship.MoveUp();
				//ship_pos.y -= ship_speed;
			}
		}
	}

	// Fire bullet
	if( keyboard.KeyIsPressed( VK_SPACE ) )
	{
		ship.Fire( Dt );
		//if( fire_rate_tracker >= fire_rate )
		//{
		//	if( bullet_count < max_bullets )
		//	{
		//		// Reset fire rate tracker
		//		fire_rate_tracker = 0.f;
		//
		//		// Helpful var to determine ships center for bullet spawning
		//		const float ship_half_size = ship_size * .5f;
		//
		//		// Set bullet to ship center
		//		const float ship_center_x = ship_pos.x + ship_half_size;
		//		const float ship_center_y = ship_pos.y + ship_half_size;
		//		bullet_x[ bullet_count ] = ship_center_x;
		//		bullet_y[ bullet_count ] = ship_center_y;
		//
		//		// Determine travel direction of bullet
		//		const float dx = ( screen_width * .5f ) - ship_center_x;
		//		const float dy = ( screen_height * .5f ) - ship_center_y;
		//		const float rcp_dist = 1.f / sqrt( dx*dx + dy*dy );
		//		bullet_vx[ bullet_count ] = dx * rcp_dist;
		//		bullet_vy[ bullet_count ] = dy * rcp_dist;
		//
		//		// Increase bullet count
		//		++bullet_count;
		//	}
		//}
	}

	ship.ChangeDirection( ship_direction );
	// m_ship.SetPosition(ship_pos);
}

void Player::Draw( Graphics & Gfx )
{
	{ // Draw ship
		const int x = ( int )ship.pos.x;
		const int y = ( int )ship.pos.y;
		const int w = ( int )ship.size.width;
		Gfx.DrawRect( x, y, w, w, Colors::White );
	}
}

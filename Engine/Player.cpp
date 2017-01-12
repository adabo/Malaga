#include "Player.h"
#include "Keyboard.h"
#include "ChiliWin.h"

Player::Player( Keyboard & Kbd )
	:
	m_keyboard( Kbd )
{}

void Player::Update()
{
	// Helpful vars for checking if ship is on/near edges
	const float screen_width = ( float )Graphics::ScreenWidth;
	const float screen_height = ( float )Graphics::ScreenHeight;
	const float right_bounds = screen_width - 1.f - ship_size;
	const float lower_bounds = screen_height - 1.f - ship_size;

	Vector ship_pos = m_ship.GetPos();
	// Move clockwise
	if( m_keyboard.KeyIsPressed( VK_LEFT ) || m_keyboard.KeyIsPressed( 'A' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x < right_bounds )
		{
			ship_pos.x += ship_speed;
		}
		else if( ship_pos.y >= lower_bounds && ship_pos.x > 0.f )
		{
			ship_pos.x -= ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y > 0.f )
			{
				ship_pos.y -= ship_speed;
			}
			else if( ship_pos.x >= right_bounds && ship_pos.y < lower_bounds )
			{
				ship_pos.y += ship_speed;
			}
		}
	}

	// Move counter clockwise
	if( m_keyboard.KeyIsPressed( VK_RIGHT ) || m_keyboard.KeyIsPressed( 'D' ) )
	{
		if( ship_pos.y <= 0.f && ship_pos.x > 0.f )
		{
			ship_pos.x -= ship_speed;
		}
		else if( ship_pos.y >= lower_bounds && ship_pos.x < right_bounds )
		{
			ship_pos.x += ship_speed;
		}
		else
		{
			if( ship_pos.x <= 0.f && ship_pos.y < lower_bounds )
			{
				ship_pos.y += ship_speed;
			}
			else if( ship_pos.x >= right_bounds && ship_pos.y > 0.f )
			{
				ship_pos.y -= ship_speed;
			}
		}
	}

	// Fire bullet
	if( m_keyboard.KeyIsPressed( VK_SPACE ) )
	{
		if( fire_rate_tracker >= fire_rate )
		{
			if( bullet_count < max_bullets )
			{
				// Reset fire rate tracker
				fire_rate_tracker = 0.f;

				// Helpful var to determine ships center for bullet spawning
				const float ship_half_size = ship_size * .5f;

				// Set bullet to ship center
				const float ship_center_x = ship_pos.x + ship_half_size;
				const float ship_center_y = ship_pos.y + ship_half_size;
				bullet_x[ bullet_count ] = ship_center_x;
				bullet_y[ bullet_count ] = ship_center_y;

				// Determine travel direction of bullet
				const float dx = ( screen_width * .5f ) - ship_center_x;
				const float dy = ( screen_height * .5f ) - ship_center_y;
				const float rcp_dist = 1.f / sqrt( dx*dx + dy*dy );
				bullet_vx[ bullet_count ] = dx * rcp_dist;
				bullet_vy[ bullet_count ] = dy * rcp_dist;

				// Increase bullet count
				++bullet_count;
			}
		}
	}
}

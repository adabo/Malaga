#include "Player.h"
#include "Amalgum.h"
#include "ChiliWin.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Utilities.h"

Player::Player( Keyboard & Kbd, Mouse &Mse, Amalgum &rAmalgum )
	:
	keyboard( Kbd ),
	mouse( Mse ),
	amalgum( rAmalgum ),
	ship( rAmalgum.ship )
{}

void Player::Update( float Dt )
{
	// Helpful vars for checking if ship is on/near edges
	const SizeF screen = {
		( float )Graphics::ScreenWidth,
		( float )Graphics::ScreenHeight
	};
	const SizeF ship_size = SizeF(
		static_cast< float >( ship.width ),
		static_cast< float >( ship.height )
	);
	const SizeF bounds = screen - ship_size - SizeF( 1.f, 1.f );

	
	Vector ship_direction{};

	// Move clockwise
	if( keyboard.KeyIsPressed( VK_LEFT ) || keyboard.KeyIsPressed( 'A' ) )
	{
		if( ship.position.y <= 0.f && ship.position.x < bounds.width )
		{
			ship_direction = { 1.f, 0.f };
		}
		else if( ship.position.y >= bounds.height && ship.position.x > 0.f )
		{
			ship_direction = { -1.f, 0.f };
		}
		else
		{
			if( ship.position.x <= 0.f && ship.position.y > 0.f )
			{
				ship_direction = { 0.f, -1.f };
			}
			else if( ship.position.x >= bounds.width && ship.position.y < bounds.height )
			{
				ship_direction = { 0.f, 1.f };
			}
		}
	}

	// Move counter clockwise
	else if( keyboard.KeyIsPressed( VK_RIGHT ) || keyboard.KeyIsPressed( 'D' ) )
	{
		if( ship.position.y <= 0.f && ship.position.x > 0.f )
		{
			ship_direction = { -1.f, 0.f };
		}
		else if( ship.position.y >= bounds.height && ship.position.x < bounds.width )
		{
			ship_direction = { 1.f, 0.f };
		}
		else
		{
			if( ship.position.x <= 0.f && ship.position.y < bounds.height )
			{
				ship_direction = { 0.f, 1.f };
			}
			else if( ship.position.x >= bounds.width && ship.position.y > 0.f )
			{
				ship_direction = { 0.f, -1.f };
			}
		}
	}

	// Fire bullet
	if( keyboard.KeyIsPressed( VK_SPACE ) )
	{
		if( amalgum.weapon.CanFire() )
		{
			if( amalgum.projectile_list.size() < amalgum.max_bullets )
			{
				// Helpful var to determine ships center for bullet spawning
				const SizeF ship_half_size = ship_size * .5f;
		
				// Set bullet to ship center
				const Vector ship_center = ship.position + ship_half_size;

				// Add projectile to list in amalgum				
				amalgum.projectile_list.emplace_back( Projectile( ship_center, ( Amalgum::screen_size - ship_center ).Normalize(), 3, 5, 300.f ) );
			}
		}
	}

	amalgum.ship.velocity = ( ship_direction * ship.speed );
}

void Player::Draw( Graphics & Gfx )
{
	ship.Draw( Gfx );
}

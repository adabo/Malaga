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
	ship( amalgum.ship )
{}

void Player::Update( float Dt )
{
	// Helpful vars for checking if ship is on/near edges	
	const SizeF ship_size = SizeF(
		static_cast< float >( ship.width ),
		static_cast< float >( ship.height )
	);
	const SizeF bounds = Amalgum::screen_size - ship_size - SizeF( 1.f, 1.f );

	
	Vector ship_direction{ 0.f, 0.f };

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
			/*if( amalgum.projectile_list.size() < amalgum.max_bullets )
			{*/
				// Helpful var to determine ships center for bullet spawning
				const SizeF ship_half_size = ship_size * .5f;
		
				// Set bullet to ship center
				const Vector ship_center = ship.position + ship_half_size;

				Vector dir(0.f, 0.f);
				if( ship.position.x == 0.f )
				{
					dir.x = 1.f;
				}					
				else if( ship.position.x == Amalgum::screen_size.width - ship_size.width -1.f )
				{
					dir.x = -1.f;
				}					
				else if( ship.position.y == 0.f )
				{
					dir.y = 1.f;
				}
				else
				{
					dir.y = -1.f;
				}
					
				// Add projectile to list in amalgum
				amalgum.projectile_list.emplace_back( Projectile( ship_center, dir, 3, 5, 300.f ) );
			//}
		}
	}

	amalgum.ship.velocity = ( ship_direction * ship.speed );
}

void Player::Draw( Graphics & Gfx )
{
	ship.Draw( Gfx );
	amalgum.shield.Draw( ship.position, Gfx );
}

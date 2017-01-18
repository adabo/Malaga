#include "StarField.h"
#include "Graphics.h"
#include "Random.h"

StarField::StarField()
	:
	m_stars( m_star_count )
{
	for( auto &star : m_stars)
	{
		const float x = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenWidth - 1 ) );
		const float y = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenHeight - 1 ) );
		star.m_pos = Vector( x, y );
		star.m_speed = Random::GetRandomFloat( 0.f, 15.f );
	}
}

void StarField::Update( float Dt )
{
	for( auto &star : m_stars )
	{
		auto &pos = star.m_pos;
		pos.y += ( star.m_speed * Dt );
		
		if( pos.y >= static_cast< float >( Graphics::ScreenHeight ) )
		{	
			pos.x = Random::GetRandomFloat( 0.f, static_cast< float >( Graphics::ScreenWidth - 1 ) );
			pos.y = 0.f;
			star.m_speed = Random::GetRandomFloat( 0.f, 15.f );
			if( pos.x < 0.f || pos.x >= 800.f ||
				pos.y < 0.f || pos.y >= 600.f )
			{
				int a = 0;
			}
		}
	}
}

void StarField::Draw( Graphics & Gfx )const
{
	for( auto &star : m_stars )
	{
		const int x = max( static_cast< int >( star.m_pos.x ) - 1, min( Graphics::ScreenWidth - 1, 0 ) );
		const int y = max( static_cast< int >( star.m_pos.y ) - 1, min( Graphics::ScreenHeight - 1, 0 ) );
		Gfx.PutPixel( x, y, Colors::White );
	}
}

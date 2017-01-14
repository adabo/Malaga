#include "StarField.h"
#include "Graphics.h"

StarField::StarField()
	:
	rng( std::seed_seq() ),
	m_stars( m_star_count )
{
	std::uniform_int_distribution<int> xDist( 0, Graphics::ScreenWidth );
	std::uniform_int_distribution<int> yDist( 0, Graphics::ScreenHeight );
	std::uniform_real_distribution<float> spdDist( 0.f, 4.f );

	for( auto &star : m_stars)
	{
		const float x = static_cast<float>( xDist( rng ) );
		const float y = static_cast<float>( yDist( rng ) );
		star.m_pos = Vector( x, y );
		star.m_speed = spdDist( rng );
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
			std::uniform_int_distribution<int> xDist( 0, Graphics::ScreenWidth );
			std::uniform_real_distribution<float> spdDist( 0.f, 4.f );
			pos.x = static_cast<float>( xDist( rng ) );
			star.m_speed = spdDist( rng );
		}
	}
}

void StarField::Draw( Graphics & Gfx )const
{
	for( auto &star : m_stars )
	{
		const int x = static_cast< int >( star.m_pos.x );
		const int y = static_cast< int >( star.m_pos.y );
		Gfx.PutPixel( x, y, Colors::White );
	}
}

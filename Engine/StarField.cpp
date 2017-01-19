#include "StarField.h"
#include "Amalgum.h"
#include "Graphics.h"
#include "Random.h"

StarField::StarField()
	:
	stars( star_count )
{

	for( auto &star : stars )
	{
		const float x = Random::GetRandomFloatInRange( 0.f, Amalgum::screen_size.width );
		const float y = Random::GetRandomFloatInRange( 0.f, Amalgum::screen_size.height );
		star.pos = Vector( x, y );
		star.speed = Random::GetRandomFloatInRange( 0.f, 15.f );
	}
}

void StarField::Update( float Dt )
{	
	for( auto &star : stars )
	{
		star.pos.y += ( star.speed * Dt );
		if( star.pos.y >= Amalgum::screen_size.height )
		{
			star.pos.x = Random::GetRandomFloatInRange( 0.f, Amalgum::screen_size.width );
			star.pos.y = 0.f;
		}
	}
}

void StarField::Draw( Graphics & Gfx )const
{
	for( auto &star : stars )
	{
		const int x = std::max( 0, std::min( Graphics::ScreenWidth - 1, static_cast< int >( star.pos.x ) ) );
		const int y = std::max( 0, std::min( Graphics::ScreenHeight - 1, static_cast< int >( star.pos.y ) ) );
		Gfx.PutPixel( x, y, Colors::White );
	}
}

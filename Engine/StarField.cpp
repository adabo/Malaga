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
		const float x = Random::GetRandomFloat( 0.f, Amalgum::screen_size.width );
		const float y = Random::GetRandomFloat( 0.f, Amalgum::screen_size.height );
		star.pos = Vector( x, y );
		star.speed = Random::GetRandomFloat( 0.f, 15.f );
	}
}

void StarField::Update( float Dt )
{	
	for( auto &star : stars )
	{
		star.pos.y += ( star.speed * Dt );
		if( star.pos.y >= Amalgum::screen_size.height )
		{
			star.pos.x = Random::GetRandomFloat( 0.f, Amalgum::screen_size.width );
			star.pos.y = 0.f;
		}
	}
}

void StarField::Draw( Graphics & Gfx )const
{
	for( auto &star : stars )
	{
		const int x = max( 0, min( Graphics::ScreenWidth - 1, static_cast< int >( star.pos.x ) ) );
		const int y = max( 0, min( Graphics::ScreenHeight - 1, static_cast< int >( star.pos.y ) ) );
		Gfx.PutPixel( x, y, Colors::White );
	}
}

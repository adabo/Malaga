#include "Amalgum.h"

SizeF Amalgum::screen_size = { ( float )Graphics::ScreenWidth, ( float )Graphics::ScreenHeight };

Amalgum::Amalgum( Keyboard & Kbd, Mouse &Mse )
	:
	shield( 1.f ),
	ship( { 0.f, 0.f }, { 0.f, 0.f }, 32, 32, 300.f, 1.f, 1.f ),
	player( Kbd, Mse, *this ),
	view( *this ),
	spawner( *this ),
	text_score( "Score: " ),
	text_shield( "Shields: " ),
	text_level( "Level: " )
{}

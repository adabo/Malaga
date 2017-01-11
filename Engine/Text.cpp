#include "Text.h"
#include "Graphics.h"
#include <sstream>

//Text::Color Text::dc = GREY;
Color Text::fixedSys_surf[ 512 * 84 ];
Color Text::edges_surf[ 160 * 29 ];
Font Text::fixedSys;
Font Text::edges;
// Font Text::font;

Text::Text( std::string Str, int X, int Y, WhichFont Type, eColor DC, eColor MC, StrType SType )
	: str( Str ),
	s_type( SType ),
	x( X ),
	y( Y ),
	type( Type ),
	mouse_over_color( MC ),
	default_color( DC ),
	left_is_pressed( false )
{
	// Set font
	switch( type )
	{
		case FIXEDSYS:
		{
			fixedSys.LoadFont( &fixedSys, fixedSys_surf, "Fixedsys16x28.bmp", 16, 28, 32 );
			// Assign reference to 'font' so that you can use it for the rest of the program
			font = &fixedSys;
		}
		break;
		case EDGES:
		{
			edges.LoadFont( &edges, edges_surf, "Edges_5x9x32.bmp", 5, 9, 32 );
			font = &edges;
		}
		break;
	}

	SetBuff();
	// Set default color
	SetColor( default_color );
}

bool Text::Update( Mouse& Mouse )
{
	int mx = Mouse.GetPosX();
	int my = Mouse.GetPosY();

	if( px != NULL && py != NULL )
	{
		x = *px;
		y = *py;
	}

	ToString();

	SetColor( default_color );
	if( Mouse.IsInWindow() )
	{
		if( MouseHoverOver( mx, my, x, y, w, h ) )
		{
			SetColor( mouse_over_color );
			if( Mouse.LeftIsPressed() )
			{
				if( !left_is_pressed )
				{
					left_is_pressed = true;
				}
			}
			else
			{
				if( left_is_pressed )
				{
					// For some reason, if you don't set the color back to
					// default here, then it will flash it's old color when
					// switch back to that screen. "<=" is a different object
					// on every shop_screen. So you have to account for that
					// when you are assigning colors.
					SetColor( default_color );
					left_is_pressed = false;
					return true;
				}
			}
		}
	}
	return false;
}

void Text::Draw( Graphics &Gfx )
{
	// int string_width = sprintf(buffer, "HP: %.2f", ThisPlayer.hp);
	// string_width = string_width * fixedSys.char_width;

	font.DrawString( str.c_str(), x, y, &font, color, Gfx );
}

void Text::SetIToA( int IStr )
{
	std::stringstream ss;
	ss << IStr;	
	str = ss.str();
	SetBuff();
}

void Text::SetFToA( float FStr )
{
	std::stringstream ss;
	ss.precision( 2 );
	ss << FStr;
	str = ss.str();
	SetBuff();
}

bool Text::MouseHoverOver( int MX, int MY, int X, int Y, int W, int H )
{
	return (
		MX >= X && MX <= X + W &&
		MY >= Y && MY <= Y + H
		);
}

void Text::SetColor( Color C )
{
	active_color = C;
}

Color Text::GetColor()const
{
	return color;
}

std::string Text::GetStr()
{
	return str;
}

void Text::SetStr( std::string Str )
{
	str = Str;
}

void Text::SetBuff()
{
	w = str.length() * font->char_width;
	h = font->char_height;
}

void Text::SetX( int X )
{
	x = X;
}

void Text::SetY( int Y )
{
	y = Y;
}
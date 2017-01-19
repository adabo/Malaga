#include "Text.h"
#include "Graphics.h"
#include <iomanip>
#include <sstream>


Font TextFormat::fixedSys( L"Assets/Fixedsys16x28.bmp", 16, 28, 32 );
Font TextFormat::edges( L"Assets/Edges_5x9x32.bmp", 5, 9, 32 );

/*******************************************************   TextFormat Class ***************************************/
TextFormat::TextFormat( WhichFont Type, Color C )
	:
	type( Type ),
	color( C ),
	font( ( type == FIXEDSYS ) ? &fixedSys : &edges )
{
}

void TextFormat::SetColor( Color C )
{
	color = C;
}

Color TextFormat::GetColor()const
{
	return color;
}


/*******************************************************   Text Class ***************************************/
Text::Text( int Value )
{
	std::stringstream ss;
	ss << Value;
	str = ss.str();
}

Text::Text( float Value )
{
	std::stringstream ss;	
	ss << std::setprecision( 2 ) << std::fixed << Value;
	*this = Text( ss.str() );
}

Text::Text( const std::string & String )
	:
	str( String )
{}

Text::Text( std::string && String )
	:
	str( std::move( String ) )
{}

Text::Text( const Text & Src )
	:
	Text( Src.str )
{}

Text::Text( Text && Src )
	:
	Text( std::move( Src.str ) )
{}

Text & Text::operator=( const Text & Src )
{
	*this = Text( Src );
	return *this;
}

Text & Text::operator=( Text && Src )
{
	str = std::move( Src.str );
	return *this;
}

const std::string &Text::GetStr()const
{
	return str;
}

Text & Text::Append( const Text & Src )
{
	str.append( Src.str );
	return *this;
}

Text Text::Append( const Text & Src ) const
{
	return Text( *this ).Append( Src );
}


#include "Bitmap.h"
#include "Colors.h"

Bitmap::Bitmap( const std::wstring & Filename )
	:
	Image( Filename )
{}

Color Bitmap::GetPixel( int X, int Y ) const
{
	const Color *temp = reinterpret_cast< const Color * >( m_pBits.get() );
	return temp[ X + ( Y * m_width ) ];
}

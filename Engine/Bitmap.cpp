#include "Bitmap.h"
#include "Colors.h"

Bitmap::Bitmap( const std::wstring & Filename, const Wic &crWic )
	:
	Image( Filename, crWic )
{}

Color Bitmap::GetPixel( int X, int Y ) const
{
	const Color *temp = reinterpret_cast< const Color * >( m_pBits.get() );
	return temp[ X + ( Y * m_width ) ];
}

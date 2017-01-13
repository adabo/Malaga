#include "Bitmap.h"

Bitmap::Bitmap( const std::wstring & Filename, const Wic &crWic )
	:
	Image( Filename, crWic )
{}

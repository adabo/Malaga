#pragma once

#include "Image.h"

class Color;

class Bitmap : public Image
{
public:
	Bitmap( const std::wstring &Filename );
	Color GetPixel( int X, int Y )const;
};
#pragma once

#include "Image.h"

class Color;

class Bitmap : public Image
{
public:
	Bitmap( const std::wstring &Filename, const Wic &crWic);
	Color GetPixel( int X, int Y )const;
};
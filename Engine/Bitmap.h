#pragma once

#include "Image.h"

class Bitmap : public Image
{
public:
	Bitmap( const std::wstring &Filename, const Wic &crWic);
};
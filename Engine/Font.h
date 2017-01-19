#pragma once

#include <string>
#include "Bitmap.h"

class Color;
class Graphics;
class Wic;

class Font
{
public:
    Font(const std::wstring &Filename, int CharWidth, int CharHeight,
		  int CharsPerRow );
    
	void DrawChar( char c, int x, int y, Color color, Graphics &Gfx );
	void DrawString( const std::string &buffer, int x, int y, Color color, Graphics &Gfx );
    int char_width;
    int char_height;
    int n_chars_per_row;
    Bitmap bmp;
};

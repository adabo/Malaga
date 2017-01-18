#include "Font.h"
#include "Graphics.h"
#include <assert.h>

Font::Font( const std::wstring &Filename, int CharWidth, int CharHeight, int CharsPerRow, const Wic &rWic )
	:
	bmp( Filename, rWic ),
	char_width( CharWidth ),
	char_height( CharHeight ),
	n_chars_per_row( CharsPerRow )
{}

void Font::DrawString( const std::string &buffer, int x_offset, int y_offset, Color color, Graphics &Gfx )
{
	int index = 0;
	for( auto &c : buffer )
	{
		DrawChar( c, x_offset + index * char_width, y_offset, color, Gfx );
		++index;
	}
}

void Font::DrawChar( char c, int x_offset, int y_offset, Color color, Graphics &Gfx )
{
    if( c < ' ' || c > '~' )
        return;

    const int sheet_index = c - ' ';
    const int sheet_col = sheet_index % n_chars_per_row;
    const int sheet_row = sheet_index / n_chars_per_row;
    const int x_start = sheet_col * char_width;
    const int y_start = sheet_row * char_height;
    const int x_end = x_start + char_width;
    const int y_end = y_start + char_height;
    const int surf_width = char_width * n_chars_per_row;

	const int x_start_pos = x_offset - x_start;
	const int y_start_pos = y_offset - y_start;
	
    for( int y = y_start; y < y_end; y++ )
    {
        for( int x = x_start; x < x_end; x++ )
        {
			if( bmp.GetPixel( x, y ) == Colors::Black )
            {
				Gfx.PutPixel( x + x_start_pos, y + y_start_pos, color );
            }
        }
    }
}

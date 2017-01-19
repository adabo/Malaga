#pragma once

#include <stdio.h>
#include <string>
#include "Colors.h"
#include "Font.h"
#include "Mouse.h"

class Graphics;

class TextFormat
{
public:
	enum WhichFont
	{
		FIXEDSYS, EDGES
	};

	TextFormat( WhichFont Type, Color C );

	Color GetColor()const;
	void SetColor( Color C );

	WhichFont type;
	Color color;
	static Font fixedSys;
	static Font edges;
	Font *font;
};

class Text
{
public:
	Text( int Value );
	Text( float Value );
	Text( const std::string &String );
	Text( std::string &&String );
	Text( const Text &Src );
	Text( Text &&Src );

	Text &operator=( const Text &Src );
	Text &operator=( Text &&Src );

	const std::string &GetStr()const;

	Text &Append( const Text &Src );
	Text Append( const Text &Src )const;

private:
	std::string str;
	
};

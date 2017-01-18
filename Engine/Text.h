#pragma once

#include <stdio.h>
#include <string>
#include "Colors.h"
#include "Font.h"
#include "Mouse.h"

class Graphics;
class Wic;

class Text
{
public:
    enum WhichFont
    {
        FIXEDSYS, EDGES
    };
public:
	Text() = default;
	Text( const std::string &Str, int X, int Y, WhichFont Type, Color DefaultColor, Color MouseOverColor, const Wic &rWic );

    void Draw( Graphics &Gfx);
    bool Update(Mouse& Mouse);

    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)const;
	
	Color GetColor()const;		
    const std::string &GetStr()const;

    void SetIToA(int IStr);
    void SetFToA(float FStr);
    void SetColor(Color C);
    void SetBuff();
    void SetStr(const std::string &Str);

	void SetXY( int X, int Y );
    void SetX(int X);
    void SetY(int Y);

private:
    int x, y, w, h;
    std::string str;
    WhichFont type;
	Color default_color, mouse_over_color, active_color;
    Font fixedSys;
    Font edges;

	Font *font;
    bool left_is_pressed;
};

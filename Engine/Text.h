#pragma once

#include <stdio.h>
#include <string>
#include "Colors.h"
#include "Font.h"
#include "Mouse.h"

class Graphics;

class Text
{
public:
    enum StrType
    {
        STRING, INT, FLOAT
    };

    enum eColor
    {
        GREY	= Colors::Gray.dword, 
		PINK	= Colors::Magenta.dword, 
		GREEN	= Colors::Green.dword, 
		BLACK	= Colors::Black.dword, 
		RED		= Colors::Red.dword
    };

    enum WhichFont
    {
        FIXEDSYS, EDGES
    };
public:
	Text() = default;
    Text(std::string Str, int X, int Y, WhichFont Type, eColor DC, eColor MC, StrType SType = STRING);

    void Draw( Graphics &Gfx);
    bool Update(Mouse& Mouse);

    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
		
    eColor GetDC();
    eColor GetMC();
	Color GetColor()const;
		
    std::string GetStr();

    void SetIToA(int IStr);
    void SetFToA(float FStr);
    void SetColor(Color C);
    void SetBuff();
    void SetStr(std::string Str);
    void SetX(int X);
    void SetY(int Y);

private:
    StrType s_type;
    int x, y, w, h;
    std::string str;
    WhichFont type;
	Color default_color, mouse_over_color, active_color;
    static Color fixedSys_surf[512 * 84]; // fixedSys
    static Color edges_surf[160 * 29];    // edges
    static Font fixedSys;
    static Font edges;
    Font *font;
    bool left_is_pressed;
};

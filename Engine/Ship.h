#pragma once
#include "Vector."
#include "Entity.h"

class Ship : public Entity
{
public:
	Ship( const Vector &Pos, const Vector &Heading, int Width = 0,
		  int Height = 0, float Speed = 30.f, float HP = 1.f, float Damage = .1f );

	void Update( float Dt ) override;
	void Draw( Graphics &Gfx ) override;
	void ClampToScreenEdges();

public:
	
	bool is_colliding,
		 // Keyboard + mouse input
	     is_left_pressed,
	     is_right_pressed,
	     is_space_pressed,
	     is_Lmouse_pressed;
};

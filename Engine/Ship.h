#pragma once
#include "Vector."
#include "Entity.h"

class Ship : public Entity
{
public:
	Ship( Vector Pos, bool IsColliding = false );

	void Draw();
	void Update();

	bool IsColliding( const Vector &OtherPosition, float Width, float Height )override;
	bool DoCollision( float CollisionCost )override;
	void DoInput();
	void ClampToScreenEdges();

public:
	
	bool is_colliding,
		 // Keyboard + mouse input
	     is_left_pressed,
	     is_right_pressed,
	     is_space_pressed,
	     is_Lmouse_pressed;
};

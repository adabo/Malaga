#pragma once
#include "Vector."
#include "Entity.h"

class Ship : public Entity
{
public:
	Ship( Vector Pos, bool IsColliding = false );

	void Draw();
	void Update();

	bool IsColliding();
	void DoInput();
	void ClampToScreenEdges();

public:
	Vector pos;
	bool is_colliding;
};

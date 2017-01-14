#pragma once
#include "Entity.h"


class Weapon : public Entity
{
public:
    Weapon();

	bool IsColliding();
	void DoCollision();

	void Update( float Dt );
	void Draw();
private:
};


#pragma once

class Entity
{
public:
	Entity();
    Entity( float x, float y, float Hp, bool IsAlive );
public:
	float x, y,
		  hp,
		  damage;
	bool  is_alive;
	int	  w, h;
};


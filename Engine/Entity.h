#pragma once

class Entity
{
public:
	Entity();
    Entity( float x, float y, float Hp, bool IsAlive );

	virtual bool IsColliding();
	virtual void DoCollision();

	virtual void Update();
	virtual void Draw();

public:
	float x, y,
		  hp,
		  damage;
	bool  is_alive;
	int	  w, h;
};


#pragma once

#include "Entity.h"
#include "Collision.h"

class Graphics;

class EnemyHoming :
	public Entity
{
public:
	EnemyHoming(const Vector &Pos, const Vector &Dir, float Width, float Height, Color C);
	~EnemyHoming();
		
	bool IsColliding( const Vector &OtherPosition, float Width, float Height )const override;
	void DoCollision( float CollisionCost ) override;

	void Update( float Dt )override;
	void Draw( Graphics &Gfx )override;

	void SetPlayerPosition( const Vector &PlayerPos );

private:
	Vector player_pos;

};


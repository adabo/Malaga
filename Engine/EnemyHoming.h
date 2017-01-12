#pragma once

#include "Entity.h"
#include "Collision.h"

class Graphics;

class EnemyHoming :
	public Entity, public Collision
{
public:
	EnemyHoming();
	~EnemyHoming();
		
	bool IsColliding( const Vector &OtherPosition, float Width, float Height )const override;
	void DoCollision( float CollisionCost ) override;

	void Update( float Dt )override;
	void Draw( Graphics &Gfx )override;

	void SetPlayerPosition( const Vector &PlayerPos );

private:
	Vector m_player_pos;

};


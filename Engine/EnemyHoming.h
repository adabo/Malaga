#pragma once

#include "Entity.h"

class Graphics;

class EnemyHoming :
	public Entity
{
public:
	EnemyHoming();
	~EnemyHoming();

	void SetPlayerPosition( const Vector &PlayerPos );
	void Update( float Dt )override;
	void Draw( Graphics &Gfx );

private:
	Vector m_player_pos;
};


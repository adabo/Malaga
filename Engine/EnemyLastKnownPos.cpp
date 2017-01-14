#include "EnemyLastKnownPos.h"


void EnemyLastKnownPos::Update( float Dt)
{
    float frame_step = velocity * Dt;
    x += frame_step * x;
    y += frame_step * y;
}

void EnemyLastKnownPos::Draw()
{}


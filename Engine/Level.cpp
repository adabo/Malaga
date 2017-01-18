#include "Level.h"

Level::Level()
{}

void Level::IncreaseKillCount()
{
	++kill_count;
	if( kill_count >= tier_goal && difficulty_tier < 9 )
		++difficulty_tier;
}

int Level::GetDifficulty() const
{
	return difficulty_tier;
}

void Level::SetDifficulty( int Lvl )
{
	difficulty_tier = Lvl;
}

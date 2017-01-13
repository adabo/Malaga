#include "Level.h"

Level::Level()
{}

int Level::GetDifficulty() const
{
	return m_difficulty_tier;
}

void Level::SetDifficulty( int Lvl )
{
	m_difficulty_tier = Lvl;
}

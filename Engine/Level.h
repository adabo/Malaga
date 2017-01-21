#pragma once

class Level
{
public:
    Level();

	void IncreaseKillCount();

	int GetDifficulty()const;
	void SetDifficulty( int Lvl );

private:
	const unsigned int tier_goal = 10u;
	unsigned int kill_count = 0u;
	int difficulty_tier = 0;
};


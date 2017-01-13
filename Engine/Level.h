#pragma once

class Level
{
public:
    Level();

	int GetDifficulty()const;
	void SetDifficulty( int Lvl );

private:	
	int m_difficulty_tier = 0;
};


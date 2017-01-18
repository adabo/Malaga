#pragma once

#include <algorithm>
#include <vector>

#include "Entity.h"

class Reaper
{
public:
	template<class T>
	static void ClaimDead( std::vector<T> &Container )
	{
		const auto old_end = Container.end();
		const auto new_end = std::remove_if( Container.begin(), old_end, []( Entity &E )
		{
			return !E.is_alive;
		} );
		if( new_end != old_end ) 
			Container.erase( new_end, old_end );
	}
};


// *************
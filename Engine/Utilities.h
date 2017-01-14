#pragma once

#include "Size.h"
#include "Vector.h"

inline Vector operator+( const SizeF &Size, const Vector &V )
{
	return Vector( V.x + Size.width, V.y + Size.height );
}
inline Vector operator+( const Vector &V, const SizeF &Size)
{
	return Vector( V.x + Size.width, V.y + Size.height );
}

inline Vector operator-( const SizeF &Size, const Vector &V )
{
	return Vector( V.x - Size.width, V.y - Size.height );
}
inline Vector operator-( const Vector &V, const SizeF &Size )
{
	return Vector( V.x - Size.width, V.y - Size.height );
}


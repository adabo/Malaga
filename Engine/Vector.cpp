#include "Vector.h"
#include <math.h>

Vector::Vector( float x, float y )
	:
	x(x),
	y(y)
{ }

Vector::Vector()
{}

Vector Vector::operator+( const Vector &VecRhs )const
{
	return Vector( x + VecRhs.x, y + VecRhs.y );
}

Vector Vector::operator-( const Vector &VecRhs )const
{
	return Vector( x - VecRhs.x, y - VecRhs.y );
}

Vector Vector::operator*( const float Rhs )const
{
	return Vector( x * Rhs, y * Rhs );
}

float Vector::GetMagnitude( ) const
{
	return sqrt( x * x + y * y );
}

Vector Vector:: GetNormal( ) const
{
	float mag = GetMagnitude();
	return Vector( x / mag, y / mag );
}


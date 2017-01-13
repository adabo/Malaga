#pragma once

struct Vector
{
	Vector( float x, float y );
	Vector();
	Vector operator+( const Vector &VecRhs )const;
	Vector operator-( const Vector &VecRhs )const;
	Vector operator*( const float Rhs )const;
	float GetMagnitude( ) const;
	Vector GetNormal() const;
	float x, y;
};

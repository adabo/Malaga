#pragma once

struct Vector
{
	Vector() = default;
	Vector( float x, float y );
	Vector operator+( const Vector &VecRhs )const;
	Vector operator-( const Vector &VecRhs )const;
	Vector operator*( const float Rhs )const;
	float GetMagnitude( ) const;
	Vector GetNormal() const;
	float x = 0.f, y = 0.f;
};

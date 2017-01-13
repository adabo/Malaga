/******************************************************************************************
*    Chili DirectX Framework Version 16.07.20                                              *
*    Game.h                                                                                *
*    Copyright 2016 PlanetChili.net <http://www.planetchili.net>                           *
*                                                                                          *
*    This file is part of The Chili DirectX Framework.                                     *
*                                                                                          *
*    The Chili DirectX Framework is free software: you can redistribute it and/or modify   *
*    it under the terms of the GNU General Public License as published by                  *
*    the Free Software Foundation, either version 3 of the License, or                     *
*    (at your option) any later version.                                                   *
*                                                                                          *
*    The Chili DirectX Framework is distributed in the hope that it will be useful,        *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                        *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         *
*    GNU General Public License for more details.                                          *
*                                                                                          *
*    You should have received a copy of the GNU General Public License                     *
*    along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

#include <chrono>
#include <iostream>

#include "Amalgum.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Wic.h"


//class MyClass
//{
//public:
//	MyClass &operator+=( const MyClass &Source )
//	{
//		f += Source.f;
//		g += Source.g;
//
//		return *this;
//	}
//	MyClass operator-( const MyClass &Source )const
//	{
//		MyClass temp;
//		temp.f = this->f - Source.f;
//		temp.g = this->g - Source.g;
//		return temp;
//
//		// or 
//
//		return MyClass{ f - Source.f, g - Source.g };
//	}
//	MyClass Add( const MyClass &A, const MyClass &B )
//	{
//		MyClass temp = A;
//		temp.f += B.f;
//		temp.g += B.g;
//		return temp;
//
//		// or
//
//		return MyClass( A ) += B;
//	}
//public:
//	float f, g;
//};
//
//
//MyClass operator+( const MyClass &A, const MyClass &B )
//{
//	MyClass temp = A;
//	temp.f += B.f;
//	temp.g += B.g;
//	return temp;
//	
//	// or
//	MyClass c = A - B;
//	return MyClass( A ) += B;
//}


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;

	// I've grown accustomed to useing m_ for member prefix
	// I will still use (_) for rest of name instead of camel case
	// WIC stands for (Windows Imaging Component) it's the new
	// API for loading images after GDI+
	//
	// I'm also going to try using C++ exceptions for this project,
	// make it a learning experience for me as well, so it doesn't
	// get stale.
	Wic m_wic;

	Amalgum m_amalgum;

	// Temp ship variables
	float ship_x = 0.f;
	float ship_y = 0.f;
	const float ship_speed = 3.f;
	const float ship_size = 32.f;

	// Temp bullet variables
	constexpr static unsigned int max_bullets = 10u;
	unsigned int bullet_count = 0;
	float bullet_x[ max_bullets ];
	float bullet_y[ max_bullets ];
	float bullet_vx[ max_bullets ];
	float bullet_vy[ max_bullets ];
	const float bullet_length = 5.f;
	const float bullet_speed = 10.f;
	constexpr static float fire_rate = .1f;
	float fire_rate_tracker = 0.f;

	float m_frame_time = 0.f;
	
	// Temp enemy variables
	// TODO: Create three enemies
	// TODO: Decide formula for ship speeds
	/*
	1) Moves straight (from any side ?)
	2) Moves straight at player's current position when spawned
	3) Chases player
	*/
};

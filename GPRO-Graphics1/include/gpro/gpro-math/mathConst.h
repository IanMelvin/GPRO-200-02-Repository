#pragma once
/*
	Writen By Ian Melvin
	File: mathConst.h
	Purpose: The purpose of this file is to hold math functions, constant variables, and include statements outside of prexitsing files

	Contriubters:
	Ian Melvin
*/

#ifndef MATH_CONST_H
#define MATH_CONST_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

using namespace std;

//Numerical Constent
const float INFINITE_NUMBER = numeric_limits<float>::infinity();

//Common Includes
#include "gpro/rayClass.h"
#include "gpro/gpro-math/gproVector.h"

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: inline Float function
		Description: Generates a random number.
	*/
inline float rand_float()
{
	return rand() / (RAND_MAX + 1.0f);
}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: inline float function
		Description: Takes in two floats, call the random above float generator function and coverts its values to be in the range of the floats.
	*/
inline float rand_float(float min, float max)
{
	return min + (max - min) * rand_float();
}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: inline float function
		Description: Takes in 3 floats, determines if a values is outside of a range and 
					 if so returns the closest range edge, or the value is in range and is returned.
	*/
inline float clamp(float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}
	else if (value > max)
	{
		return max;
	}
	return value;
}


#endif
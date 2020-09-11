#pragma once
/*
	mathConst.h
	Holds const mathematical values and #include headers to be used 

	Writen by Ian Melvin
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

//Random number generator
inline float rand_float()
{
	return rand() / (RAND_MAX + 1.0f);
}

inline float rand_float(float min, float max)
{
	return min + (max - min) * rand_float();
}

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
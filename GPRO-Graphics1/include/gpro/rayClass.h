#pragma once
/*
	colorr.h
	Hold the Class and basic function implementation for ray objects

	Writen by Ian Melvin
*/

#ifndef RAY_CLASS_H
#define RAY_CLASS_H

#include "gpro-math/gproVector.h"

using namespace std;

class Ray {
public:
	Ray() {}
	Ray(const vec3& origin, const vec3& direction)
	{
		this->origin = origin;
		this->direction = direction;
	}

	vec3 getOrigin() const
	{
		return origin;
	}

	vec3 getDirection() const
	{
		return direction;
	}
	
	vec3 location(float t) const
	{
		return origin + t * direction;
	}

	vec3 origin;
	vec3 direction;

};



#endif
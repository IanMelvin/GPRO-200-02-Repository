#pragma once
/*
	colorr.h
	Determine and output RGB values for pixels

	Writen by Ian Melvin
*/

#ifndef RAY_CLASS_H
#define RAY_CLASS_H

#include "gpro-math/gproVector.h"

class ray {
public:
	ray() {}
	ray(const vec3& origin, const vec3& direction)
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
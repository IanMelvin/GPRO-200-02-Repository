#pragma once
/*
	Writen By Ian Melvin
	File: rayClass.h
	Purpose: The purpose of this file is to delcare and implement the ray class

	Contriubters:
	Ian Melvin
*/

#ifndef RAY_CLASS_H
#define RAY_CLASS_H

#include "gpro-math/gproVector.h"

using namespace std;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Description: Declares and implements all values related to the class.
	*/
class Ray {
public:

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Class Constructors
		Description: Takes in values from instance of class, stores them in variables of the class.
	*/
	Ray() {}
	Ray(const vec3& origin, const vec3& direction)
	{
		this->origin = origin;
		this->direction = direction;
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: vec3 returning function
		Description: Returns the value stored in the origin variable.
	*/
	vec3 getOrigin() const
	{
		return origin;
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: vec3 returning function
		Description: Returns the value stored in the direction variable.
	*/
	vec3 getDirection() const
	{
		return direction;
	}
	
	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: vec3 returning function
		Description: Calculates and returns the location of the ray based on the origin of the ray.
	*/
	vec3 location(float t) const
	{
		return origin + t * direction;
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Description: Two vec3 variables are declared.
	*/
	vec3 origin;
	vec3 direction;

};



#endif
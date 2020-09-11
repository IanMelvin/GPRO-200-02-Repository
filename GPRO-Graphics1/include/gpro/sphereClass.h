#pragma once
/*
	Writen By Ian Melvin
	File: sphereClass.h
	Purpose: The purpose of this file is to delcare and implement the Sphere class

	Contriubters:
	Ian Melvin
*/

#ifndef SPHERE_CLASS_H
#define SPHERE_CLASS_H

#include "gpro-math/gproVector.h"
#include "Hitter.h"
#include <cmath>

using namespace std;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Class Type: Child Class
		Description: Declaration and implementation of variables and functions of the class.
	*/
class Sphere : public Hittable {
public: 

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Class Constructors
		Description: Takes the input for each instance of the class and stores them in variables of the class.
	*/
	Sphere()
	{
		
	}
	Sphere(vec3 center, float radius)
	{
		this->center = center;
		this->radius = radius;
	}
	

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Overloading function declaration
	*/
	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const override;


	vec3 center;
	float radius = 0.0f;

};

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: bool returning function
		Description: Takes a ray, two floats and a hit_record and determines if a ray hit said sphere and return true if hit, or false if miss
	*/
bool Sphere::hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const
{
	vec3 oc = ray.getOrigin() - center;
	float temp1 = ray.getDirection().length(false);
	float temp2 = dot(oc, ray.getDirection());
	float temp3 = oc.length(false) - radius * radius;
	float discriminant = temp2 * temp2 - temp1 * temp3;
	
	if (discriminant > 0)
	{
		float root = sqrt(discriminant);
		float storage = (-temp2 - root) / temp1;

		if (storage < temp_max && storage > temp_min)
		{
			record.temp = storage;
			record.point = ray.location(record.temp);
			vec3 outward_normal = (record.point - center) / radius;
			record.set_face_normal(ray, outward_normal);
			return true;
		}

		storage = (-temp2 + root) / temp1;
		if (storage < temp_max && storage > temp_min)
		{
			record.temp = storage;
			record.point = ray.location(record.temp);
			vec3 outward_normal = (record.point - center) / radius;
			record.set_face_normal(ray, outward_normal);
			return true;
		}
	}
	
	return false;
}

#endif
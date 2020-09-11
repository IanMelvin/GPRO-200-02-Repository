#pragma once
/*
	Writen By Ian Melvin
	File: camraClass.h
	Purpose: The purpose of this file is to delcare and implement the camera class

	Contriubters:
	Ian Melvin
*/

#ifndef HITTER_H
#define HITTER_H
#include "gpro-math/gproVector.h"
#include "rayClass.h"
#include <memory>
#include <vector>

using namespace std;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Code type: struct declaration
		Description: Declares a struct template, with component variables and an inline based function
	*/
struct hit_record {
	vec3 point;
	vec3 perpendicular;
	float temp = 0.0f;
	bool frontOrBack = false;;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: inline void function
		Description: Takes in a ray and a vec3, determines what direction is the ray is coming from and sets the direction of the vector, perpendicular to the hit object.
	*/
	inline void set_face_normal(const Ray& ray, const vec3& outward_normal)
	{
		frontOrBack = dot(ray.getDirection(), outward_normal) < 0;
		if (frontOrBack)
		{
			perpendicular = outward_normal;
		}
		else
		{
			perpendicular = -outward_normal;
		}
	}
};

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Class Type: Abstract Class
		Description: Declaration of an basic class wit one function intended to be overriten by each of its child classes
	*/
class Hittable {
public:
	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const = 0;
};

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Class Type: Child Class
		Description: Child of Hittable class, declaration and implementation of class functions and vector
	*/
class Hittable_List : public Hittable {
public: 

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: Class Constructors 
		Description: When a new object of said class in declared, the component of the class is taken and added to a vector of all of the instances of the class
	*/
	Hittable_List() {}
	Hittable_List(shared_ptr<Hittable> object)
	{
		add(object);
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: void function
		Description: Empties vector of all instances of object stored in the vector
	*/
	void clear()
	{
		objects.clear();
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Function Type: void function
		Description: Takes in an object and adds it to the vector
	*/
	void add(shared_ptr<Hittable> object)
	{
		objects.push_back(object);
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Function Declaration
		Description: declares this classes version of parent function to override to override the parent
	*/
	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const override;


	//Vector declaration
	vector<shared_ptr<Hittable>> objects;
};

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Bool returing Function
		Description: Takes a ray, two floats and a hit_record and determines if the ray has collided with any of the objects in the vector
	*/
bool Hittable_List::hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const
{
	hit_record temp_record;
	bool hit_anything = false;
	int value = 0;
	float closest = temp_max;

	for (int i = 0; i < objects.size(); i++) 
	{
		if (objects[i]->hit(ray, temp_min, closest, temp_record))
		{
			hit_anything = true;
			closest = temp_record.temp;
			record = temp_record;
		}
	}

	return hit_anything;
}


#endif
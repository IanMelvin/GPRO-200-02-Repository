/*
	Writen By Ian Melvin
	File: camraClass.h
	Purpose: The purpose of this file is to delcare and implement the camera class

	Contriubters:
	Ian Melvin
*/
#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include "gpro/gpro-math/mathConst.h"

using namespace std;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Description: Declaration and implementation of variables and functions of the class
	*/
class Camera {
public:
	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Constructor for the Camera Class
		Description: Declares, and assigns values to variables and data types to be used for each active instance of the class
	*/
	Camera()
	{
		float aspect_ratio = 16.0f / 9.0f;
		float viewport_height = 2.0f;
		float viewport_width = aspect_ratio * viewport_height;
		float focal_length = 1.0f;

		origin = vec3(0, 0, 0);
		horizontal = vec3(viewport_width, 0.0f, 0.0f);
		vertical = vec3(0.0f, viewport_height, 0.0f);
		lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0.0f, 0.0f, focal_length);
	}

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: Function returing a ray
		Description: Takes in two floats and creates a ray along with existing camera vec3 variables
	*/
	Ray getRay(float u, float v) const
	{
		return Ray(origin, lower_left_corner + u*horizontal + v*vertical -origin );
	}


private:
	//vec3 data type declarations
	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	
};

#endif
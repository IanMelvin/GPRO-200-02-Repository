#pragma once
/*
	Writen By Ian Melvin
	File: color.h
	Purpose: The purpose of this file implement functions related to pixel color

	Contriubters:
	Ian Melvin
*/
#ifndef COLOR_H
#define COLOR_H

#include "gpro-math/gproVector.h"
#include <iostream>
#include <fstream>

#include "gpro/gpro-math/mathConst.h"
#include "Hitter.h"
#include "sphereClass.h"

using namespace std;


//Math constant
const float RGB_CONVERSION = 256.0f;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: void function
		Description: Takes in an file output stream, a vec3 and an integer. Calculates the rgb values and outputs them to the .ppm file for the shader to work 
	*/
void color_maker(ofstream &out, vec3 pixel_color, int samples_per_pixel)
{
	float red = pixel_color.getX();
	float green = pixel_color.getY();
	float blue = pixel_color.getZ();

	float scale = 1.0f / samples_per_pixel;

	red *= scale;
	green *= scale;
	blue *= scale;

	out << static_cast<int>(RGB_CONVERSION * clamp(red, 0.0f, 0.999f)) << " "
		<< static_cast<int>(RGB_CONVERSION * clamp(green, 0.0f, 0.999f)) << " "
		<< static_cast<int>(RGB_CONVERSION * clamp(blue, 0.0f, 0.999f)) << endl;
}

/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: void function
		Description: Empties vector of all instances of object stored in the vector
	*/
vec3 ray_color(const Ray& ray, const Hittable& world)
{
	hit_record record;
	if (world.hit(ray, 0, INFINITE_NUMBER, record))
	{
		return 0.5f * (record.perpendicular + vec3(1,1,1));
	}
	vec3 unit_direction = unit_vector(ray.getDirection());
	float temp = 0.5f * (unit_direction.getY() + 1.0f);
	return (1.0f - temp) * vec3(1.0f, 1.0f, 1.0f) + temp * vec3(0.5f, 0.7f, 1.0f);

	//Old version of ray_color
	/*
	float temp = hit_sphere(vec3(0, 0, -1), 0.5, ray);
	if (temp > 0.0)
	{
		vec3 N = unit_vector(ray.location(temp) - vec3(0, 0, -1));
		return 0.5f * vec3(N.getX() + 1, N.getY()+1, N.getZ()+1);
	}

	vec3 unit_direction = unit_vector(ray.getDirection());
	temp = 0.5f * (unit_direction.getY() + 1.0f);
	return (1.0f - temp) * vec3(1.0f, 1.0f, 1.0f) + temp * vec3(0.5f, 0.7f, 1.0f);
	*/
}



#endif
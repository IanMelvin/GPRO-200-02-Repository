#pragma once
/*
	color.h
	Functions related to managing the color output for the image

	Writen by Ian Melvin
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
const float RGB_CONVERSION = 255.999f;

void color_maker(ofstream &out, vec3 pixel_color)
{
	out << static_cast<int>(RGB_CONVERSION * pixel_color.getX()) << " "
		<< static_cast<int>(RGB_CONVERSION * pixel_color.getY()) << " "
		<< static_cast<int>(RGB_CONVERSION * pixel_color.getZ()) << endl;
}

float hit_sphere(const vec3& center, float radius, const Ray& ray)
{
	vec3 oc = ray.getOrigin() - center;
	float temp1 = ray.getDirection().length(false);
	float temp2 = dot(oc, ray.getDirection());
	float temp3 = oc.length(false) - radius*radius;
	float discriminant = temp2 * temp2 - temp1 * temp3;
	if (discriminant < 0)
	{
		return -1.0f;
	}
	else
	{
		return (-temp2 - sqrt(discriminant)) / temp1;
	}
}

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
#pragma once
/*
	colorr.h
	Functions related to managing the color output for the image

	Writen by Ian Melvin
*/

#ifndef COLORR_H
#define COLORR_H

#include "gpro-math/gproVector.h"
#include <iostream>
#include "rayClass.h"

using namespace std;

const float RGB_CONVERSION = 255.999f;

void color_maker(ostream &out, vec3 pixel_color)
{
	out << static_cast<int>(RGB_CONVERSION * pixel_color.getX()) << " "
		<< static_cast<int>(RGB_CONVERSION * pixel_color.getY()) << " "
		<< static_cast<int>(RGB_CONVERSION * pixel_color.getZ()) << endl;
}

vec3 ray_color(const ray& ray)
{
	vec3 unit_direction = unit_vector(ray.getDirection());
	float temp = 0.5f * (unit_direction.getY() + 1.0f);
	return (1.0f - temp) * vec3(1.0f, 1.0f, 1.0f) + temp * vec3(0.5f, 0.7f, 1.0f);
}



#endif
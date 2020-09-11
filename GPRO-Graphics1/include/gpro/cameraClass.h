#pragma once
/*
	colorr.h
	Holds Class definition for the Camera Class

	Writen by Ian Melvin
*/

#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include "gpro/gpro-math/mathConst.h"

using namespace std;

class Camera {
public:
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

	Ray getRay(float u, float v) const
	{
		return Ray(origin, lower_left_corner + u*horizontal + v*vertical -origin );
	}

private:
	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	
};

#endif
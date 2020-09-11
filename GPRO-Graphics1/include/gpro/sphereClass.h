#pragma once
/*
	colorr.h
	Holds Objects based on the Hittable class

	Writen by Ian Melvin
*/

#ifndef SPHERE_CLASS_H
#define SPHERE_CLASS_H

#include "gpro-math/gproVector.h"
#include "Hitter.h"
#include <cmath>

using namespace std;

class Sphere : public Hittable {
public: 
	Sphere() {}
	Sphere(vec3 center, float radius)
	{
		this->center = center;
		this->radius = radius;
	}

	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const override;

	vec3 center;
	float radius;
};

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
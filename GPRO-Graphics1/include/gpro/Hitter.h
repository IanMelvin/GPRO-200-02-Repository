#pragma once
/*
	colorr.h
	Holds the Classes Hittable and Hittable List

	Writen by Ian Melvin
*/

#ifndef HITTER_H
#define HITTER_H
#include "gpro-math/gproVector.h"
#include "rayClass.h"
#include <memory>
#include <vector>

using namespace std;

struct hit_record {
	vec3 point;
	vec3 perpendicular;
	float temp = 0.0f;
	bool frontOrBack = false;;

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

class Hittable {
public:
	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const = 0;
};

class Hittable_List : public Hittable {
public: 
	Hittable_List() {}
	Hittable_List(shared_ptr<Hittable> object)
	{
		add(object);
	}

	void clear()
	{
		objects.clear();
	}

	void add(shared_ptr<Hittable> object)
	{
		objects.push_back(object);
	}

	virtual bool hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const override;

	vector<shared_ptr<Hittable>> objects;
};

bool Hittable_List::hit(const Ray& ray, float temp_min, float temp_max, hit_record& record) const
{
	hit_record temp_record;
	bool hit_anything = false;
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
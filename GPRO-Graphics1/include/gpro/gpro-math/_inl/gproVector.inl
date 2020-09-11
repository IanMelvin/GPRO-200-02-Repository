/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	gproVector.h
	Interface for vectors. Sets an example for C and C++ compatible headers.

	Modified by: ____________
	Modified because: ____________
*/

/*
	Modified By Ian Melvin
	File: gproVector.inl
	Purpose: The purpose of the file is to implement functions related to the vec3 data type

	Contriubters:
	Ian Melvin

	Intial code provided by Daniel S. Buckstein
*/

#ifdef _GPRO_VECTOR_H_
#ifndef _GPRO_VECTOR_INL_
#define _GPRO_VECTOR_INL_


#ifdef __cplusplus

#include "gpro\gpro-math\gproVector.h"

inline vec3::vec3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}
inline vec3::vec3(float const xc, float const yc, float const zc)
	: x(xc), y(yc), z(zc)
{
}
inline vec3::vec3(float3 const vc)
	: x(vc[0]), y(vc[1]), z(vc[2])
{
}
inline vec3::vec3(vec3 const& rh)
	: x(rh.x), y(rh.y), z(rh.z)
{
}

inline vec3& vec3::operator =(vec3 const& rh)
{
	x = rh.x;
	y = rh.y;
	z = rh.z;
	return *this;
}

inline vec3& vec3::operator +=(vec3 const& rh)
{
	x += rh.x;
	y += rh.y;
	z += rh.z;
	return *this;
}

inline vec3 const vec3::operator +(vec3 const& rh) const
{
	return vec3((x + rh.x), (y + rh.y), (z + rh.z));
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Overriding the multiplication operator between a float variable and a vec3 data type by multipling each component of vec3 with the float and returns the new vec3
*/
inline vec3 operator*(float t, const vec3 &vector)
{
	return vec3(t * vector.getX(), t * vector.getY(), t * vector.getZ());
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Overriding the multiplication operator between two vec3 by multipling the parallel conponents (v1.x * v2.x, etc), and returns the new vec3
*/
inline vec3 operator*(const vec3 &vector1, const vec3 &vector2)
{
	return vec3(vector1.getX() * vector2.getX(), vector1.getY() * vector2.getY(), vector1.getZ() * vector2.getZ());
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Overriding the division operator between a float variable and a vec3 data type by multipling the vec3 by one over the float
*/
inline vec3 operator/ (vec3 vector, float t)
{
	return (1 / t) * vector;
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Overriding the subtraction operator between two vectors by subtracting the parallel components (v1.x * v2.x, etc), and returns the new vec3
*/
inline vec3 operator-(const vec3 &vector1, const vec3 &vector2)
{
	return vec3(vector1.getX() - vector2.getX(), vector1.getY() - vector2.getY(), vector1.getZ() - vector2.getZ());
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Takes in two vectiors, mutliplying each parallel component (v1.x * v2.x, etc), then returning the sum of the multiplied components
*/
inline float dot(const vec3 &vector1, const vec3 &vector2)
{
	return (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY()) + (vector1.getZ() * vector2.getZ());
}

/*
  Implemented by Ian Melin
  Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
  Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
  Function type: inline vec3 returning function
  Description: Takes in a vec3 and divides the vec3 by the squareroot of the length of the vector, to get a vec3 of length 1
*/
inline vec3 unit_vector(vec3 vector)
{
	return vector / vector.length(true);
}

#endif	// __cplusplus


inline floatv vec3default(float3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0.0f;
	return v_out;
}
inline floatv vec3init(float3 v_out, float const xc, float const yc, float const zc)
{
	v_out[0] = xc;
	v_out[1] = yc;
	v_out[2] = zc;
	return v_out;
}
inline floatv vec3copy(float3 v_out, float3 const v_rh)
{
	v_out[0] = v_rh[0];
	v_out[1] = v_rh[1];
	v_out[2] = v_rh[2];
	return v_out;
}

inline floatv vec3add(float3 v_lh_sum, float3 const v_rh)
{
	v_lh_sum[0] += v_rh[0];
	v_lh_sum[1] += v_rh[1];
	v_lh_sum[2] += v_rh[2];
	return v_lh_sum;
}

inline floatv vec3sum(float3 v_sum, float3 const v_lh, float3 const v_rh)
{
	return vec3init(v_sum, (v_lh[0] + v_rh[0]), (v_lh[1] + v_rh[1]), (v_lh[2] + v_rh[2]));
}



#endif	// !_GPRO_VECTOR_INL_
#endif	// _GPRO_VECTOR_H_
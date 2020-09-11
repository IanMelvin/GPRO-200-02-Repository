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
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: ____________
	Modified because: ____________
*/

/*
	Modified By Ian Melvin
	File: GPRO-Graphics1-TestConsole-main.cpp
	Purpose: The purpose of this file is run all the shaders

	Contriubters:
	Ian Melvin

	Intial code provided by Daniel S. Buckstein
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "gpro/gpro-math/mathConst.h"
#include "gpro/color.h"
#include "gpro/Hitter.h"
#include "gpro/sphereClass.h"
#include "gpro/cameraClass.h"

using namespace std;

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Description: Declaration of constant variables. 
	*/
const float aspect_ratio = 16.0f / 9.0f;
const int IMAGE_WIDTH = 400;
const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / aspect_ratio);
const int SAMPLES_PER_PIXEL = 100;

void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}

	/*
		Modified by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Function Type: main program function
		Description: Declares values for program and runs the inital code to start the process. 
	*/
int main(int const argc, char const* const argv[])
{
	//Daniel S. Buckstein's
	testVector();

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Description: Declaration of objects to be shaded
	*/
	Hittable_List world;
	world.add(make_shared<Sphere>(vec3(0, 0, -1), 0.5f)); //main rainbow sphere
	world.add(make_shared<Sphere>(vec3(0, -100.5, -1), 100.0f)); //ground sphere

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Description: Declares instance of camera
	*/
	Camera cam;
	
	/*
		Implemented by Ian Melin
		Description: Opens output file stream for pixel values to be sent and turned into the outputed image
	*/
	ofstream file("image.ppm");

	/*
		Implemented by Ian Melin
		Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
		Used components of The pre-existing framework by Daniel S. Buckstein https://github.com/dbucksteincc/GPRO-Graphics1
		Description: Outputing inital values to file, then goes through each pixel and calculates what the rgb value of each pixel is through calling functions
	*/
	file << "P3" << endl << IMAGE_WIDTH << " " << IMAGE_HEIGHT << endl << "255" << endl;

	for (int i = IMAGE_HEIGHT-1; i >= 0; i--)
	{
		cerr << "\rScanLines remaining: " << i << " " << flush;

		for (int k = 0; k < IMAGE_WIDTH; k++)
		{
			vec3 pixel_color(0, 0, 0);
			for (int j = 0; j < SAMPLES_PER_PIXEL; j++)
			{
				float u = (k + rand_float()) / (IMAGE_WIDTH-1);
				float v = (i + rand_float()) / (IMAGE_HEIGHT - 1);

				Ray ray = cam.getRay(u, v);
				pixel_color += ray_color(ray, world);
			}

			color_maker(file, pixel_color, SAMPLES_PER_PIXEL);

		}


		
	}

	cerr << endl << "Done!" << endl;
	
	/*
		Implemented by Ian Melin
		Description: Closes FileStream
	*/
	file.close();


	//Daniel S. Buckstein's
	printf("\n\n");
	system("pause");
}

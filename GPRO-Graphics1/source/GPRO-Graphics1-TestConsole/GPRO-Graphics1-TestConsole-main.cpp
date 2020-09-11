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


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "gpro/gpro-math/gproVector.h"
#include "gpro/colorr.h"
#include "gpro/rayClass.h"

using namespace std;

//Image constants
const float aspect_ratio = 16.0f / 9.0f;
const int IMAGE_WIDTH = 400;
const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / aspect_ratio);


//Original Constants
/*
const int IMAGE_WIDTH = 256;
const int IMAGE_HEIGHT = 256;
const float RGB_CONVERSION = 255.999f;
*/

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


int main(int const argc, char const* const argv[])
{
	testVector();

	//Camera variables
	float viewport_height = 2.0f;
	float viewport_width = 2.0f;
	float focal_length = 1.0f;

	vec3 origin = vec3(0, 0, 0);
	vec3 horizontal = vec3(viewport_width, 0, 0);
	vec3 vertical = vec3(0, viewport_height, 0);
	vec3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	//Rendering
	ofstream file("image.ppm");

	file << "P3" << endl << IMAGE_WIDTH << " " << IMAGE_HEIGHT << endl << "255" << endl;

	for (int i = IMAGE_HEIGHT-1; i >= 0; i--)
	{
		cerr << "\rScanLines remaining: " << i << " " << flush;

		for (int k = 0; k < IMAGE_WIDTH; k++)
		{
			float u = float(k) / (IMAGE_WIDTH - 1);
			float v = float(i) / (IMAGE_HEIGHT - 1);
			ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
			vec3 pixel_color = ray_color(ray);
			color_maker(file, pixel_color);

			//Orignal implementation
			/*
			float red = float(k) / (IMAGE_WIDTH-1);
			float green = float(i) / (IMAGE_HEIGHT-1);
			float blue = 0.25;

			int intRed = static_cast<int>(RGB_CONVERSION * red);
			int intGreen = static_cast<int>(RGB_CONVERSION * green);
			int intBlue = static_cast<int>(RGB_CONVERSION * blue);

			file << intRed << " " << intGreen << " " << intBlue << endl;
			*/
		}


		
	}

	cerr << endl << "Done!" << endl;

	printf("\n\n");
	system("pause");
}

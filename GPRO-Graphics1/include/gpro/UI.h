#pragma once
/*
	Writen By Ian Melvin
	File: camraClass.h
	Purpose: The purpose of this file is to delcare and implement related to user choices

	Contriubters:
	Ian Melvin
*/

#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include "gpro/gpro-math/gproVector.h"
#include "gpro/Hitter.h"
#include "gpro/sphereClass.h"

using namespace std;

	/*
		Implemented by Ian Melin
		Description: Asks for and collects user input to return.
	*/

int userInput()
{
	string storage = " ";
	bool loop = true;

	cout << endl << "Hello, welcome to the shader program";
	cout << endl;
	system("pause");
	cout << endl << "1. Would you like to run the default program (Generate rainbow cirlce with a green circle base)?";
	cout << endl << "2. Or would you like to run the pokla dot program (You choice where, the size, and how many circles are on the screen )";
	cout << endl << "3. Exit";

	do
	{
		cout << endl << "Enter the number corresponding to the program you wish to run: ";
		cin >> storage;

		if (storage == "1" || storage == "2" || storage == "3")
		{
			loop = false;
			return stoi(storage);
		}
		else
		{
			cout << endl << endl << "You appear to have entered an invalid responce, please try again.";
		}
	} while (loop);
	
	return 4;
}

		/*
			Implemented by Ian Melin
			A line of code (107) is Based on code provided by Peter Shirley in his book https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
			Description: Declaration of objects to be shaded
		*/
void circleChooser(Hittable_List& worlds)
{
	vector<vec3> colors;
	float circleCount = 10, x = 0, y = 0, z = 0, radius = 0;

	string input = " ";
	bool loop = true;
	
	while(loop)
	{
		
		cout << endl;
		cout << "You have " << circleCount << " circles availbe to put on screen" << endl;
		cout << "Would you like to add a circle? (y/n)" << endl;
		cin >> input;
		cin.ignore();

		if (input != "y")
		{
			loop = false;
			break;
		}

		cout << "Enter a number for your x coord but be careful, if you go to big or small(negative) you won't see your circle:" << endl;
		cin >> x;
		cin.ignore();
		

		cout << "Enter a number for your y coord but be careful, if you go to big or small(negative) you won't see your circle:" << endl;
		cin >> y;
		cin.ignore();
		

		cout << "Enter a number for your z coord but be careful, if you go to big or small(negative) you won't see your circle:" << endl;
		cin >> z;
		cin.ignore();
		

		cout << "Enter a number for your radius:" << endl;
		cin >> radius;
		cin.ignore();
	
		
		worlds.add(make_shared<Sphere>(vec3(x, y, z), radius));

		circleCount--;
		
		if (circleCount == 0)
		{
			loop = false;
		}
	}
}



#endif
/*
Name: Alex Giesbrecht
Created Date: 3/12/2017
Description: Header file for the tsp class.
*/

#pragma once

#include "cities.h"
#include <chrono>

class tsp
{
	struct bestSwap
	{
		bestSwap() : i(), j() {};
		int i;
		int j;
	};

public:
	static int nearestNeighborRoute(cities*);
	static int twoOpt(cities*);	
	static void twoOptSwap(cities *, cities *, int, int);
};
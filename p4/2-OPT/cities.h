/*
Name: Alex Giesbrecht
Created Date: 3/12/2017
Description: Header file for the cities class.
*/

#pragma once

#include "city.h"
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef vector<city> cityList;

class cities
{	
public:
	cityList lst;

	cities();
	~cities();
	void pushCity(int id, int x, int y);
	void swap(int, int);
	void optSwap(int, int);
	city getCity(int);
	int size();
	int getDistance(int, int);
	int getTotalDistance();
};


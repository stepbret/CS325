#pragma once

#ifndef RESULTS_H
#define RESULTS_H

#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

class Results 
{
public:
	Results();
	int numCoins;
	vector<int> coinDist;

	void zeroResults();
	void printResults(const std::vector<int>&, string);
	void writeResults(const std::vector<int>&, int, string, string);
};

#endif

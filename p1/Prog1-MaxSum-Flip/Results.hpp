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
	int first;
	int last;
	int sum;

	void zeroResults();
	void printResults(const std::vector<int>&, string);
	void writeResults(const std::vector<int>&, string, string);
};

#endif
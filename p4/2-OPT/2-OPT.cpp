// Program4-OPT2.cpp : Defines the entry point for the console application.

#include "tsp.h"
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// function declarations
int writeRoute(string, int, cities*);

int main(int argc, char* argv[])
{
	// if incorrect number of arguments, send usage message to cerr and return with error code 1
	if (argc > 2)
	{
		cerr << "USAGE: opt2 <problem_file_name>" << endl;
		return 1;
	}

	// city & route lists
	cities* citiesList = new cities();

	// length of the estimated shortest route
	int routeLength;

	string problemFileName = argv[1];
	string outfileName = problemFileName + ".tour";

	ifstream infile;
	
	infile.open(problemFileName);

	string cityData;

	if (infile.is_open())
	{
		// get data for each city from problem file
		while (getline(infile, cityData))
		{
			stringstream cityss(cityData);

			// data point retrieved from stringstream
			int data;

			// loop counter for data points
			int j = 0;

			// date points about the city
			int id = 0;
			int xCoord = 0;
			int yCoord = 0;
		
			// while there are still data points in the line read from problemsFile...
			while (cityss >> data)
			{
				// if data is the id, store id
				if (j == 0)
				{
					id = data;
				}
				// if data is the x-coordinate, store x-coordinate
				else if (j == 1)
				{
					xCoord = data;
				}
				// if data is the y-coordinate, store the y-coordinate
				else if (j == 2)
				{
					yCoord = data;
				}
				// if there are more than three data points on the line, the problemsFile is broken
				else
				{
					cerr << "BAD FORMATTING; LINE " << j << endl;
					return 1;
				}

				++j;
			}

			// add city to list of cities
			citiesList->pushCity(id, xCoord, yCoord);
		}

		infile.close();
	}
	// if there was an error opening the file...
	else
	{
		cerr << "error opening file " << problemFileName << endl;
		return 1;
	}
	
	cout << "Starting..." << endl;

	auto start = chrono::high_resolution_clock::now();
	tsp::nearestNeighborRoute(citiesList);
	tsp::twoOpt(citiesList);
	auto finish = chrono::high_resolution_clock::now();

	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(finish - start);
	
	routeLength = citiesList->getTotalDistance();
	
	// print route to file
	if (writeRoute(outfileName, routeLength, citiesList))
	{
		cerr << "error writing file " << outfileName << endl;
		return 1;
	}
	
	free(citiesList);

	cout << "Done! Time was: " << milliseconds.count() << " milliseconds" << endl;

	cin.get();

    return 0;
}

int writeRoute(string outfileName, int distance, cities* routeList)
{
	ofstream outfile;

	outfile.open(outfileName, ofstream::trunc);

	outfile << distance << endl;

	if (outfile.is_open())
	{
		for (int i = 0; i < routeList->size(); ++i)
		{
			outfile << routeList->getCity(i).id << endl;
		}

		outfile.close();
	}
	else
	{
		return 1;
	}
	
	return 0;
}
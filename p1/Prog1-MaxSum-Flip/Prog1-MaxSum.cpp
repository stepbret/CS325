// Prog1-MaxSum.cpp : Defines the entry point for the console application.
//

#include "Results.hpp"
#include "Enum.hpp"
#include "BetterEnum.hpp"
#include "divAConq.hpp"
#include "Linear.hpp"
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector<int> arrType;

void writeSet(int, string);

istream& operator >> (istream &input, arrType &arr)
{
	arr.clear();

	string inputString;
	getline(input, inputString);

	stringstream inputStream(inputString);
	string stringElement;

	while (getline(inputStream, stringElement, ' '))
	{
		stringstream streamElement(stringElement);
		int element = 0;
		streamElement >> element;

		arr.push_back(element);
	}

	return input;
}

int main()
{
	arrType arr;
	Results sumInfo;
	string inputFileName;
	string outputFileName;
	int i = 1;

	// get input file name from user
	cout << "Please enter the name of the input file: ";
	getline(cin, inputFileName);

	// get output file name from user
	cin.clear();
	cout << "Please enter the name of the output file: ";
	getline(cin, outputFileName);

	// get array values from input file
	ifstream problemsFile(inputFileName);

	// loop through and calculate max sum array for each row of test data
	if (problemsFile.good()) {

		while (problemsFile >> arr)
		{
			cout << "Problems Set " << i << endl;
			cout << "[" << endl;
			writeSet(i, outputFileName);

			// Find max sum array using Algorithm 1 - Enumeration
			sumInfo = baseEnum(arr);
			sumInfo.printResults(arr, "Enumeration");
			sumInfo.writeResults(arr, outputFileName, "Enumeration");

			cout << "\n";
			sumInfo.zeroResults();

			// Find max sum array using Algorithm 2 - Better Enumeration
			sumInfo = betterEnum(arr);
			sumInfo.printResults(arr, "Better Enumeration");
			sumInfo.writeResults(arr, outputFileName, "Better Enumeration");

			cout << "\n";
			sumInfo.zeroResults();

			// Find max sum array using Algorithm 3 - Divide and Conquer
			sumInfo = divAConq(arr, 0, arr.size() - 1);
			sumInfo.printResults(arr, "Divide & Conquer");
			sumInfo.writeResults(arr, outputFileName, "Divide & Conquer");

			cout << "\n";
			sumInfo.zeroResults();

			// Find max sum array using Algorithm 4 - Linear Time
			sumInfo = linear(arr);
			sumInfo.printResults(arr, "Linear Time");
			sumInfo.writeResults(arr, outputFileName, "Linear Time");

			cout << "]" << endl;
			cout << "\n";
			++i;
		}

		if (!problemsFile.eof())
		{
			cout << "There was a problem reading the file " << inputFileName << "." << endl;
			return 1;
		}		
	}
	else
	{
		cout << "There was a problem reading the file " << inputFileName << "." << endl;
	}

	cout << "Results have been printed to " << outputFileName << "." << endl;

	problemsFile.close();

	std::cin.get();

    return 0;
}

void writeSet(int i, string filename)
{
	bool hasText = true;

	// check if output file has text
	ifstream emptyCheck;
	emptyCheck.open(filename);
	emptyCheck.seekg(0, ios::end);
	size_t size = emptyCheck.tellg();

	// if output file does not have text, set hasText to false
	if (size == 0)
	{
		hasText = false;
	}
	emptyCheck.close();

	// Writing max sum subarray results to output file
	ofstream outfile;
	outfile.open(filename, ios::out | ios::app);

	// if output file has text, write a newline for spacing
	if (hasText)
	{
		outfile << "\n";
	}
	outfile << "Problems Set " << i << ":" << endl;

	outfile.close();
}
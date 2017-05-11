#include "Results.hpp"

Results::Results()
{
	first = 0;
	last = 0;
	sum = 0;
}

void Results::zeroResults()
{
	first = 0;
	last = 0;
	sum = 0;
}

void Results::printResults(const std::vector<int> &arr, string algorithm) 
{
	cout << "\tResults for the algorithm: " << algorithm << endl;
	cout << "\tThe maximum sum subarray is: [";

	for (int i = first; i <= last; ++i)
	{
		cout << arr[i];

		if (i != last)
		{
			cout << ", ";
		}
		else
		{
			cout << "]" << endl;
		}
	}
	cout << "\tThe maximum sum is: " << sum << endl;
}

void Results::writeResults(const std::vector<int> &arr, string filename, string algorithm)
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
	outfile << "\tResults for the algorithm: " << algorithm << endl;
	outfile << "\tThe maximum sum subarray is: [";

	for (int i = first; i <= last; ++i)
	{
		outfile << arr[i];

		if (i != last)
		{
			outfile << ", ";
		}
		else
		{
			outfile << "]" << endl;
		}
	}
	outfile << "\tThe maximum sum is: " << sum << endl;

	outfile.close();
}

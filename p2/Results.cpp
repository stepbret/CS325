#include "Results.hpp"

Results::Results()
{
	coinDist.clear();
	numCoins = 0;
}

void Results::zeroResults()
{
	coinDist.clear();
	numCoins = 0;
}

void Results::printResults(const std::vector<int> &denoms, string algorithm) 
{
	cout << algorithm << endl;

	for (size_t i = 0; i < denoms.size(); ++i)
	{
		if (i == denoms.size() - 1)
		{
			cout << denoms[i] << endl;
		}
		else
		{
			cout << denoms[i] << " ";
		}
	}

	for (size_t i = 0; i < coinDist.size(); ++i)
	{
		if (i == coinDist.size() - 1)
		{
			cout << coinDist[i] << endl;
		}
		else
		{
			cout << coinDist[i] << " ";
		}
	}

	cout << numCoins << endl;
}

void Results::writeResults(const std::vector<int> &denoms, int amount, string filename, string algorithm)
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

        
	outfile <<"Algorithm " << algorithm << ":" << endl;

	for (size_t i = 0; i < denoms.size(); ++i)
	{
		if (i == denoms.size() - 1)
		{
			outfile << denoms[i] << endl;
		}
		else
		{
			outfile << denoms[i] << " ";
		}
	}

	for (size_t i = 0; i < coinDist.size(); ++i)
	{
		if (i == coinDist.size() - 1)
		{
			outfile << coinDist[i] << endl;
		}
		else
		{
			outfile << coinDist[i] << " ";
		}
	}

	outfile << numCoins << endl;

	outfile.close();
}

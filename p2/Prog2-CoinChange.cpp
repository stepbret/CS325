// Prog2-CoinChange.cpp : Defines the entry point for the console application.
//

#include "Results.hpp"
#include "changeSlow.hpp"
#include "hr_time.hpp"
#include "changeGreedy.hpp"
#include "DPchange.hpp"
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef vector<int> arrType;

void writeTime(string, double, int);

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

int main(int argc, char **argv)
{
	srand(time(NULL));

	arrType denoms;
        arrType arr;
        string input = argv[1];
        int amount;
        ifstream inputFile(input);
        int k = 0;
        input.pop_back();
        input.pop_back();
        input.pop_back();
        input.pop_back();
        string outputFile;
        outputFile = input + "change.txt";
        while(inputFile >> denoms)
        {
          string a;
          getline(inputFile,a);
          amount = stoi(a);

          Results changeInfo;
          CStopWatch stopWatch;

          sort(denoms.begin(), denoms.end());

          for (size_t i = 0; i < denoms.size(); i++)
          {
                  changeInfo.coinDist.push_back(0);
          }

          
          //runs and prints the ChangeSlow algorithm
          //for (size_t k = 0; k < n.size(); ++k)
          //{
                          stopWatch.reset();
                          stopWatch.startTimer();
                          changeInfo = changeSlow(amount, denoms, denoms.size());
                          stopWatch.stopTimer();
                          changeInfo.printResults(denoms, "changeSlow");
                          changeInfo.writeResults(denoms, amount, outputFile, "changeSlow");
                          //cout << "It took " << stopWatch.getElapsedTime() << " seconds to complete the last operation." << endl;
                          cout << "\n";
                          writeTime(outputFile, stopWatch.getElapsedTime(), k);
                          changeInfo.zeroResults();
          //}
         
          //runs and prints the greedy algorithm
          //for (size_t k = 0; k <= n.size(); ++k)
          //{
                          stopWatch.reset();
                          stopWatch.startTimer();
                          changeInfo = changeGreedy(denoms, amount);
                          stopWatch.stopTimer();
                          changeInfo.printResults(denoms, "changeGreedy");
                          changeInfo.writeResults(denoms, amount, outputFile, "changeGreedy");
                          //cout << "It took " << stopWatch.getElapsedTime() << " seconds to complete the last operation." << endl;
                          cout << "\n";
                          writeTime(outputFile, stopWatch.getElapsedTime(), k);
                          changeInfo.zeroResults();
          //}
          //runs and prints the change DP algorithm
          //for (size_t k = 0; k < n.size(); ++k)
          //{
                          stopWatch.reset();
                          stopWatch.startTimer();
                          changeInfo = DPCoin(denoms, amount);
                          stopWatch.stopTimer();
                          changeInfo.printResults(denoms, "changeDP");
                          changeInfo.writeResults(denoms, amount, outputFile, "changeDP");
                          //cout << "It took " << stopWatch.getElapsedTime() << " seconds to complete the last operation." << endl;
                          cout << "\n";
                          writeTime(outputFile, stopWatch.getElapsedTime(), k);
                          changeInfo.zeroResults();
          //}
          k++;
        }


	return 0;
}

// function "writeTime" takes as input the name of an output file as a string and the elapsed time as a double.
// then it writes the elapsed time to the output file 
void writeTime(string filename, double time, int num)
{
  /*
	ofstream outfile;
	outfile.open(filename, ios::out | ios::app);

	outfile << "It took " << time << " seconds to complete the last operation." << endl;
	if (num != 10)
	{
		outfile << time << ",";
	}
	else
	{
		outfile << time << "\n";
	}
        
        outfile << "\n";

	outfile.close();
        */
}


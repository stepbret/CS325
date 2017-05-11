/*
	Algorithm 1 - Enumeration

	"Algorithm 1 - Enumeration" (function baseEnum) loops over each pair of indices i, j and computes the sum
	Sigma(k=1)(j)(A[k]). It keeps the greatest value sum that it finds. 
	
	This function takes an array as input and returns this sum and the first and last index of the maximum sum 
	subarray in a Results object.
*/

#include "Enum.hpp"

Results baseEnum(const std::vector<int> &arr)
{
	Results results;		// Holds the sum and the first and last index of the maximum sum subarray
	results.sum = arr[0];

	int n = arr.size();		// The number of elements in the array
	int currentSum;			// The current sum for subarray i to j

	// loop through starting index values i
	for (int i = 0; i < n; ++i) 
	{
		// for each starting index, loop through each last index j
		for (int j = i; j < n; ++j)
		{
			currentSum = 0;

			// for each subarray, i to j, and find the sum of the elements
			for (int k = i; k <= j; ++k)
			{
				currentSum += arr[k];
			}

			// check if the sum of the last subarray, i to j, is greater than the current results sum
			if (currentSum > results.sum)
			{
				results.sum = currentSum;
				results.first = i;
				results.last = j;
			}
		}
	}

	return results;
}

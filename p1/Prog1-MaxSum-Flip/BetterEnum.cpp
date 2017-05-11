/*
	Algorithm 2 - Better Enumeration

	In "Algorithm 1 - Enumeration" (function baseEnum) the same sum was computed many times. In particular, 
	note that Sigma(k=i)(j)(A[k]) could've been computed from Sigma(k=i)(j-1)(A[k]) in O(1) time, rather than starting
	from scratch. "Algorithm 2 - Better Enumeration" (function betterEnum) takes advantage of this observation.

	This function takes an array as input and returns this sum and the first and last index of the maximum sum 
	subarray in a Results object.
*/

#include "BetterEnum.hpp"

Results betterEnum(const std::vector<int> &arr)
{
	Results results;		// Holds the sum and the first and last index of the maximum sum subarray
	int currentSum;			// Holds intermediate summations so they can be compared with the current greatest sum
	
	results.sum = arr[0];

	// loop through starting index values i
	for (int i = 0; i < arr.size(); ++i)
	{
		currentSum = arr[i];

		// loop through ending index values j
		for (int j = i + 1; j < arr.size(); ++j)
		{
			// calculate new sum for subarray i to j by adding to previous sum for subarray i to j-1
			currentSum += arr[j];

			// check if sum is greater than the current max sum
			if (currentSum > results.sum)
			{
				results.first = i;
				results.last = j;
				results.sum = currentSum;
			}
		}
	}

	return results;
}
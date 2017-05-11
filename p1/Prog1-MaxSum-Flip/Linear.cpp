/*
	Algorithm 4 - Linear-Time

	"Algorithm 4 - Linear-Time" (function linear) does a single loop through the array, starting at the left end of the array 
	and progressing towards the right and keeps track of the maximum subarray sum seen so far.

	It uses the following observation to calculate the maximum sum subarray: a maximum subarray of A[1...j+1] is
	either a maximum subarray of A[1...j] or a subarray A[i...j+1], for some 1 <= i <= j+1. 

	This function takes an array as input and returns this sum and the
	first and last index of the maximum sum subarray in a Results object.
*/

#include "Linear.hpp"

Results linear(const std::vector<int> &arr) {

	Results results;
	results.sum = arr[0];
	int currentSum = arr[0];
	int start = 0;

	// loop through each element in array
	for (int i = 1; i < arr.size(); ++i)
	{
		// if the current value is less than the currentSum + the current value
		// (i.e. the current value is negative -or- the current value is positive and the current sum is positive)
		if (arr[i] < currentSum + arr[i])
		{
			currentSum += arr[i]; // add the current value to the current sum
		}
		// if the current value is greater than the current sum + the current value
		// (i.e. the current sum is negative and the current value is positive 
		// -or- the current value is negative but of greater value than the current sum)
		else if (arr[i] >= currentSum + arr[i])
		{
			currentSum = arr[i];	// set the current sum to the current value
			start = i;				// set the starting index to the current index
		}
		// if the current sum is greater than the current max sum
		if (results.sum < currentSum)
		{
			results.sum = currentSum;	// set the current max sum to the current sum
			results.first = start;		// update the first and last indices of the subarray
			results.last = i;
		}
	}

	return results;
}
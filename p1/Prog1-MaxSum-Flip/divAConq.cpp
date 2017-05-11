/*
	Algorithm 3 - Divide and Conquer

	"Algorithm 3 - Divide and Conquer" (function divAConq) recursively splits the array into two halves, and calculates
	the maximum subarray knowing that it will be either:

		* Contained entirely in the first half
		* Contained entirely in the second half
		* Made of a suffix of the first array and a prefix of the second half

	This function takes an array, its first index, and its last index as input and returns this sum and the 
	first and last index of the maximum sum subarray in a Results object.
*/

#include "divAConq.hpp"

Results divAConq(const std::vector<int> &arr, int start, int end)
{
	Results resultsL;			// Holds the sum and the first and last index of the LEFT maximum sum subarray
	Results resultsR;			// Holds the sum and the first and last index of the RIGHT maximum sum subarray
	Results resultsM;			// Holds the sum and the first and last index of the max sum subarray that crosses the midpoint

	resultsL.sum;
	resultsR.sum;

	// Variables for calculating max sum subarray that crosses the midpoint
	int tempSumMid;
	int sumMidL = 0;
	int sumMidR = 0;

	// The base case: the number of elements in the sub-array is 1
	// Return the element and its index as the max sum subarray
	if (start == end)
	{
		resultsL.sum = arr[start];
		resultsL.first = start;
		resultsL.last = end;
		return resultsL;
	}

	// If more than one element (all other cases)...
	
	// Calculate midpoint 
	int mid = (start + end) / 2;

	// Get Left and Right max sum subarrays with recursive call to divAConq
	resultsL = divAConq(arr, start, mid);		
	resultsR = divAConq(arr, mid + 1, end);
	
	// Find the max sum subarray that crosses mid
	resultsM.first = mid;
	resultsM.last = mid + 1;

	// Calculate the max sum subarray that includes midpoint on left side
	sumMidL = arr[mid];
	tempSumMid = 0;
	for (int i = mid; i >= resultsL.first; --i)
	{
		tempSumMid += arr[i];

		if (tempSumMid > sumMidL)
		{
			sumMidL = tempSumMid;
			resultsM.first = i;		// if new max sum, set first index for max sum subarray that crosses the midpoint
		}
	}

	// Calculate the max sum subarray that includes midpoint+1 on right side
	sumMidR = arr[mid+1];
	tempSumMid = 0;
	for (int i = mid + 1; i <= resultsR.last; ++i)
	{
		tempSumMid += arr[i];

		if (tempSumMid > sumMidR)
		{
			sumMidR = tempSumMid;
			resultsM.last = i;		// if new max sum, set last index for max sum subarray that crosses the midpoint
		}
	}

	// Add tempSumMidL and tempSumMidR together to get total max sum for max sum subarray that crosses the midpoint
	resultsM.sum = sumMidL + sumMidR;

	// Find greatest sum between Left, Middle, and Right subarrays and return its Results object

	// If middle subarray has largest sum, return resultsM
	if (resultsM.sum > resultsL.sum)
	{
		if (resultsM.sum > resultsR.sum)
		{
			return resultsM;
		}
	}

	// If right subarray has largest sum, return resultsR
	if (resultsR.sum > resultsL.sum)
	{
		return resultsR;
	}

	// If left subarray has largest sum, return resultsL
	return resultsL;
}
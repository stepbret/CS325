
#include "changeGreedy.hpp"


Results changeGreedy(const std::vector<int> &V, int A)
{
	Results result;
	result.numCoins = 0;
	result.coinDist.resize(V.size());
	int tempAmount = A;
	int vecLoc = 0;
	
	for(int j = V.size()-1; j >= 0; j--)
	{
		result.coinDist[j] = 0;
		
		while(V[j] <= tempAmount)
		{
			tempAmount = tempAmount - V[j];
			
			result.coinDist[j] = result.coinDist[j] + 1;
			
			result.numCoins++;
		}
		
	}
	return result;
}

/*
	Algorithm 1 - Brute Force

	"Algorithm 1 - Brute Force" (function changeSlow)

	This function takes an array of denominations and an amount to return in change and returns
	an array corresponding to the coins used to make the change and the total number of coins used
	in a Results object.
*/

#include "changeSlow.hpp"
#include <climits>

Results changeSlow(int amount, const std::vector<int> &coins, int m)
{
	Results coinInfo;
	Results tempInfo;

	tempInfo.coinDist.resize(coins.size()) ;
	coinInfo.coinDist.resize(coins.size());

	if (amount == 0)
	{
		coinInfo.numCoins = 0;
		return coinInfo;
	}

	coinInfo.numCoins = INT_MAX;

	for (size_t i = 0; i < m; i++)
	{
		if (coins[i] <= amount)
		{
			tempInfo = changeSlow(amount - coins[i], coins, m);
			tempInfo.coinDist[i]++;
			
			if (tempInfo.numCoins != INT_MAX && tempInfo.numCoins + 1 < coinInfo.numCoins)
			{
				coinInfo.numCoins = tempInfo.numCoins + 1;
				coinInfo.coinDist = tempInfo.coinDist;
			}
		}
	}
	
	return 	coinInfo;
}

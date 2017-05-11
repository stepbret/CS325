#include <limits.h>
#include <iostream>
#include <vector>
#include "Results.hpp"
/*
int DPCoin(std::vector<int> &coins, int value, std::vector<int> &returnCoinCount);

int main() {
  std::vector<int> coins;
  int value = 40;
  std::vector<int> coinCount;
  coins.push_back(10);
  coins.push_back(5);
  coins.push_back(1);

  int ret;

  ret = DPCoin(coins, value, coinCount);

  std::cout << "Min coins: "
            << ret
            << std::endl;
  std::cout << "Coin array: " << std::endl;
  for(int i = 0; i < coinCount.size(); i++)
  {
        std::cout << coinCount[i] << ", ";
  }

  return 0;
}
*/
Results DPCoin(std::vector<int> &coins, int value)
{
    int **coinCount = new int*[value + 1];
    int *results = new int[value + 1];
    results[0] = 0;
    results[1] = 1;

    for(int i = 0; i < value + 1; i++)
    {
        coinCount[i] = new int[coins.size()];
        for(int j = 0; j < coins.size(); j++)
        {
            coinCount[i][j] = 0;
        }
    }

    //create needed base coinCount
    coinCount[1][0] = 1;


    for(int i = 2; i <= value; i++)
    {
        int lastCoinIndex = -1;
        int min = INT_MAX;
        int maxJ = -1;

        for(int j = 0; j < coins.size(); j++)
        {
            if(coins.at(j) <= i)
            {
                 int current;
                 current = 1 + results[i - coins.at(j)];

                 if(current < min)
                 {
                     min = current;
                     maxJ = j;

                     if(lastCoinIndex == -1)
                     {
                         lastCoinIndex = j;
                         coinCount[i][j]++;
                     }
                     else
                     {
                         coinCount[i][lastCoinIndex]--;
                         coinCount[i][j]++;
                         lastCoinIndex = j;
                     }
                 }
            }
        }

        for(int j = 0; j < coins.size(); j++)
            coinCount[i][j] += coinCount[i - coins.at(maxJ)][j];

        results[i] = min;
    }

    //Set the return value so that we can clean up the memory
    Results res;
    res.numCoins = results[value];
    for(int i = 0; i < coins.size(); i++)
    {
        res.coinDist.push_back(coinCount[value][i]);
    }

    //Memory Cleanup 
    for(int i = 0; i < (value + 1); i++)
    {
        delete[] coinCount[i];
    }
    delete[] coinCount;
    delete[] results;
    //End Cleanup

    return res;
}

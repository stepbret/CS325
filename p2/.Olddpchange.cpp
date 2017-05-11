#include <string>
#include <cstdlib>
#include <iostream>
#include <string.h>

#define MAX 1000000

#define NELMS(a) sizeof(a) / sizeof(a[0])


int DPchange(int value, int coins[], int m, int denom[])
{
  //init the array to hold the coins
  int holds [value][m];

  //initialize the important 0s
  for(int i = 0; i < value; i++)
  {
    for(int j = 0; j < m; j++)
    {
      holds[i][j] = 0;
    }
  }

  //Base case
  int table[value + 1];
  table[0] = 0;

  //set the values to max
  for( int i = 1; i <= value; i++)
  {
    table[i] = MAX;
  }


  for(int i = 1; i <= value; i++) 
  {
    for(int j = 0; j < m; j++)
    {
      holds[j][1] = 0;
      if(coins[j] <= i)
      {
        maxJ = j;
        int sub = table[i-coins[j]];
        if(sub != MAX && sub + 1 < table[i])
        {
          table[i] = sub + 1;
        }
      }
    }
  }
  for(int j = 0; j < m; j++)
  {
    std::cout << holds[value][j] << ", ";
  }
  std::cout << std::endl;
  return table[value];
}

int main() {

  int amount = 28;
  int coins[] = {9, 1};
  int m = NELMS(coins);
  std::cout << m << std::endl;
  int denom [m]; 

  std::cout << "Minimum coins is :"
            << DPchange(amount, coins, m, denom) 
            << std::endl;
  return 0;
}

#include "tsp.h"

#define TIME_LIMIT 170000

int tsp::nearestNeighborRoute(cities * routelist)
{
	int totalDist = INT32_MAX;

	for (int i = 0; i < routelist->size() - 1; ++i)
	{
		int currentDist = 0;
		int minDist = INT32_MAX;
		int minDistCity;

		for (int k = i + 1; k < routelist->size(); ++k)
		{
			currentDist = routelist->getDistance(i, k);

			if (currentDist < minDist)
			{
				// update minimum distance;
				minDist = currentDist;

				// update minimum distance city;
				minDistCity = k;
			}
		}

		// swap the route order so that minDistCity is next in the route
		routelist->swap(i + 1, minDistCity);

		totalDist += minDist;
	}

	// add distance from end vertex to start vertex
	totalDist += routelist->getDistance(routelist->size() - 1, 0);

	return totalDist;	
}

int tsp::twoOpt(cities * currentRoute)
{
	cities * newRoute = new cities();

	int bestDistance = currentRoute->getTotalDistance();
	int bestDistanceI;
	int bestDistanceK;
	int newDistanceI;
	int newDistanceK;
	int improvement = 0;

	auto start = chrono::high_resolution_clock::now();

	do 
	{
		start:
		for (int i = 1; i < currentRoute->size() - 1; ++i)
		{
			for (int k = i + 1; k < currentRoute->size(); ++k)
			{
				
				bestDistanceI = currentRoute->getDistance(i - 1, i);

				if (k == currentRoute->size() - 1)
				{
					bestDistanceK = currentRoute->getDistance(k, 0);
				}
				else
				{
					bestDistanceK = currentRoute->getDistance(k, k + 1);
				}

				newRoute->lst = currentRoute->lst;

				newRoute->optSwap(i, k);

				newDistanceI = newRoute->getDistance(i - 1, i);

				if (k == newRoute->size() - 1)
				{
					newDistanceK = newRoute->getDistance(k, 0);
				}
				else
				{
					newDistanceK = newRoute->getDistance(k, k + 1);
				}

				improvement = (newDistanceI + newDistanceK) - (bestDistanceI + bestDistanceK);

				if (improvement < 0)
				{	
					bestDistance += improvement;
					currentRoute->lst = newRoute->lst;

					auto duration = chrono::high_resolution_clock::now();
					auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration - start);

					// checks if the time limit has been reached, if yes, ends optimization loop
					if ( milliseconds.count() > TIME_LIMIT )
					{
						goto cleanup;
					}
					else
					{
						goto start;
					}							
				}
			}
		}
	} while (improvement < 0);

cleanup:

	free(newRoute);

	return bestDistance;
}

void tsp::twoOptSwap(cities* newRoute, cities * currentRoute, int i, int k)
{
	//cities * newRoute = new cities();

	newRoute->lst = currentRoute->lst;

	newRoute->optSwap(i, k);

	//return newRoute;
}


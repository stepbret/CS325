#include "cities.h"

cities::cities()
{
}

cities::~cities()
{
}

void cities::pushCity(int id, int x, int y)
{
	city newCity;
	newCity.id = id;
	newCity.xCoord = x;
	newCity.yCoord = y;
	lst.push_back(newCity);
}

void cities::swap(int iCity, int jCity)
{
	city tempCity = lst.at(iCity);
	lst.at(iCity) = lst.at(jCity);
	lst.at(jCity) = tempCity;
}

void cities::optSwap(int iCity, int kCity)
{
	vector<city>::iterator ith = lst.begin() + iCity;
	vector<city>::iterator kth = lst.begin() + kCity;

	reverse(ith, ++kth);
}

city cities::getCity(int i)
{
	return lst.at(i);
}

int cities::size()
{
	return int(lst.size());
}

int cities::getDistance(int i, int j)
{
	int xDist = lst[i].xCoord - lst[j].xCoord;
	int yDist = lst[i].yCoord - lst[j].yCoord;

	int distance = int(round(sqrt((xDist * xDist + yDist * yDist))));

	return distance;
}

int cities::getTotalDistance()
{
	int totalDist = 0;

	for (int i = 0; i < lst.size() - 1; ++i)
	{
		totalDist += getDistance(i, i + 1);
	}

	totalDist += getDistance(int(lst.size()) - 1, 0);

	return totalDist;
}


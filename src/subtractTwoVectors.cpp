#include "mathRoutines.hpp"

std::vector<double> subtractTwoVectors(std::vector<double> vector1, std::vector<double> vector2)
{
	std::vector<double> newVector;
	for (int i = 0; i < vector2.size(); i++)
	{
		newVector.push_back(vector2[i] - vector1[i]);
	}

	return newVector;
}
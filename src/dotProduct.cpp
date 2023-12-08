#include "mathRoutines.hpp"

#include <vector>

double dotProduct(std::vector<double>& vec1, std::vector<double>& vec2)
{
	double total = 0;
	for (int i = 0; i < vec1.size(); i++)
	{
		total += (vec1[i] * vec2[i]);
	}
	return total;
}
#include "mathRoutines.hpp"

double l1Norm(std::vector<double> vector)
{
	double norm = 0.0f;
	for (const auto& element : vector)
	{
		norm += abs(element);
	}
	return norm;
}
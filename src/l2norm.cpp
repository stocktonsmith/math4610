#include "mathRoutines.hpp"

double l2Norm(std::vector<double> vector)
{
	double norm = 0.0;
	for (const auto& element : vector)
	{
		norm += element * element;
	}
	return sqrt(norm);
}
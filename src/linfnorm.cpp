#include "mathRoutines.hpp"

double linfNorm(std::vector<double> vector)
{
	double norm = 0.0f;
	for (const auto& element : vector)
	{
		if (abs(element) > norm)
		{
			norm = fabs(element);
		}
	}
	return norm;
}
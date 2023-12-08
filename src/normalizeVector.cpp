#include "mathRoutines.hpp"

#include <vector>

void normalizeVector(std::vector<double>& vec)
{
	double vectorNorm = l2Norm(vec);
	for (auto&& element : vec)
	{
		element = element / vectorNorm;
	}
}
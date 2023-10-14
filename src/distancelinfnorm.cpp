#include "mathRoutines.hpp"

double distancelinfNorm(std::vector<double> vector1, std::vector<double> vector2)
{
	return linfNorm(subtractTwoVectors(vector1, vector2));
}
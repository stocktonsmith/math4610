#include "mathRoutines.hpp"

double distancel2Norm(std::vector<double> vector1, std::vector<double> vector2)
{
	return l2Norm(subtractTwoVectors(vector1, vector2));
}
#include "mathRoutines.hpp"

double distancel1Norm(std::vector<double> vector1, std::vector<double> vector2)
{
	return l1Norm(subtractTwoVectors(vector1, vector2));
}
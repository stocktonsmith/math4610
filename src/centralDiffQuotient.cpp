#include "mathRoutines.hpp"

double centralDiffQuotient(double x, double h)
{
	return (myFunction(x + h) - myFunction(x - h)) / (2 * h);
}
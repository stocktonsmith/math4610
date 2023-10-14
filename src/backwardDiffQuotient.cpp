#include "mathRoutines.hpp"

double backwardDiffQuotient(double x, double h)
{
	return (myFunction(x) - myFunction(x - h)) / h;
}
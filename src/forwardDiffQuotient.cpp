#include "mathRoutines.hpp"

double forwardDiffQuotient(double x, double h)
{
	return (myFunction(x + h) - myFunction(x)) / h;
}
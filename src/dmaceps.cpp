#include "mathRoutines.hpp"

double dmaceps()
{
	double maceps = 0.5;
	while (1 + (maceps / 2) != 1)
	{
		maceps = maceps / 2;
	}
	return maceps;
}
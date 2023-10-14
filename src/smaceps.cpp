#include "mathRoutines.hpp"

float smaceps()
{
	float maceps = 0.5f;
	while (1 + (maceps / 2) != 1)
	{
		maceps = maceps / 2;
	}
	return maceps;
}
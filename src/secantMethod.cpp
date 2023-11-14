#include "rootFindingRoutines.hpp"
#include "mathRoutines.hpp"
#include <iostream>

double secantMethod(double x0, double x1, double tol, int maxIter) {
	int iter = 0;
	while (iter < maxIter) {
		double fx0 = myFunction(x0);
		double fx1 = myFunction(x1);
		double nextX1 = x1 - fx1 * ((x1 - x0) / (fx1 - fx0));

		if (std::abs(nextX1 - x1) < tol) {
			return x1;
		}

		x0 = x1;
		x1 = nextX1;
		iter++;
	}
	std::cout << "Max iterations reached. Root accuracy is not guaranteed." << std::endl;
	return x1;
}
#include "rootFindingRoutines.hpp"
#include "mathRoutines.hpp"
#include <iostream>

double newtonMethod(double x, double tol, int maxIter) {
	int iter = 0;

	while (iter < maxIter) {
		double fx = myFunction(x);
		double fPrimeX = myFunctionDeriv(x);
		double nextX = x - (fx / fPrimeX);
		if (std::abs(nextX - x) < tol) {
			return x;
		}
		x = nextX;
		iter++;
	}
	std::cout << "Max iterations reached. Root accuracy is not guaranteed." << std::endl;
	return x;
}
#include "rootFindingRoutines.hpp"
#include "mathRoutines.hpp"
#include <iostream>

double bisectionMethod(double a, double b, double tol, int maxIter) {
	double fa = myFunction(a);
	double fb = myFunction(b);
	double error = 10 * tol;
	int iter = 0;
	double c = 0;

	if (fa == 0) {
		return fa;
	}
	else if (fb == 0) {
		return fb;
	}
	else if (fa * fb > 0) {
		std::cout << "f(a) * f(b) > 0. This interval can't guarantee a root." << std::endl;
	}

	while (error > tol && iter < maxIter) {
		c = (a + b) / 2;
		double fc = myFunction(c);
		if (fa * fc <= 0) {
			b = c;
			fb = fc;
		}
		else {
			a = c;
			fa = fc;
		}

		error = b - a;
		iter++;
	}

	return c;
}
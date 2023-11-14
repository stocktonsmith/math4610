#include "rootFindingRoutines.hpp"
#include "mathRoutines.hpp"
#include <iostream>

double hybridMethod(double a, double b, double tol, int maxIter) {
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
		double x0 = (a + b) / 2;
		double fx0 = myFunction(x0);
		double x1 = x0 - (fx0) / myFunctionDeriv(x0);
		double fx1 = myFunction(x1);

		double nextX1 = x1 - fx1 * ((x1 - x0) / (fx1 - fx0));
		if (nextX1 >= a && nextX1 <= b) {
			c = x0;
			double fc = myFunction(c);
			for (int i = 0; i < 4; i++) {
				if (fa * fc < 0) {
					b = c;
					fb = fc;
				}
				else {
					a = c;
					fa = fc;
				}
				c = (a + b) / 2;
			}
		}
		else {
			return secantMethod(x0, x1, tol, maxIter);
		}
		iter++;
	}

	return c;
}
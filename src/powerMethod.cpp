#include "mathRoutines.hpp"
#include "linearSolverRoutines.hpp"

#include <vector>
#include <iostream>

double powerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector, double tol, int maxIter)
{
	normalizeVector(vector);
	std::vector<double> yVec = multiplySquareMatrixByVec(matrix, vector);
	double eigenvalue = dotProduct(yVec, vector);
	double error = 10 * tol;
	int iter = 0;

	while (error > tol && iter < maxIter)
	{
		std::vector<double> vectorNext = yVec;
		normalizeVector(vectorNext);
		yVec = multiplySquareMatrixByVec(matrix, vectorNext);
		double nextEigenvalue = dotProduct(yVec, vectorNext);
		error = absError(eigenvalue, nextEigenvalue);
		eigenvalue = nextEigenvalue;
		iter++;
	}

	if (iter == maxIter) {
		std::cout << "Max iterations reached. Eigenvalue may be inaccurate." << std::endl;
	}
	else {
		std::cout << "Eigenvalue found in " << iter << " iterations" << std::endl;
	}

	return eigenvalue;
}
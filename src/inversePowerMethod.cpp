#include "mathRoutines.hpp"
#include "linearSolverRoutines.hpp"

#include <vector>
#include <iostream>

double inversePowerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector,
	double mu, double tol, int maxIter)
{
	normalizeVector(vector);

	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i][i] -= mu;
	}

	std::vector<std::vector<std::vector<double>>> LU_container = squareMatrixToLU(matrix);
	std::vector<double> yVec = backSubstitutionUpperTri(LU_container[1],
		backSubstitutionLowerTri(LU_container[0], vector));

	double eigenvalue = dotProduct(yVec, vector);
	double error = 10 * tol;
	int iter = 0;

	while (error > tol && iter < maxIter)
	{
		std::vector<double> vectorNext = yVec;
		normalizeVector(vectorNext);
		LU_container = squareMatrixToLU(matrix);
		yVec = backSubstitutionUpperTri(LU_container[1],
			backSubstitutionLowerTri(LU_container[0], vectorNext));

		double nextEigenvalue = dotProduct(yVec, vectorNext);
		error = absError(eigenvalue, nextEigenvalue);
		eigenvalue = nextEigenvalue;
		iter++;
	}

	if (iter == maxIter)
	{
		std::cout << "Max iterations reached. Eigenvalue may be inaccurate." << std::endl;
	}
	else {
		std::cout << "Eigenvalue found in " << iter << " iterations" << std::endl;
	}

	return (1 / eigenvalue) + mu;
}
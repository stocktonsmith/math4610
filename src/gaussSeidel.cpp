#include "linearSolverRoutines.hpp"

#include <iostream>
#include <format>
#include <cmath>

std::vector<double> gaussSeidel(const std::vector<std::vector<double>> matrix, const std::vector<double> rhs,
	std::vector<double> x0, double tol, int maxIter)
{
	std::vector<double> prevX(matrix.size());

	double error = 10 * tol;
	int iter = 0;

	while (error > tol && iter < maxIter)
	{
		prevX = x0;
		for (size_t i = 0; i < matrix.size(); i++)
		{
			double sum = 0;
			for (size_t j = 0; j < matrix.size(); j++)
			{
				if (i != j)
				{
					sum += matrix[i][j] * x0[j];
				}
			}
			x0[i] = (rhs[i] - sum) / matrix[i][i];
		}

		double sum = 0;
		for (size_t i = 0; i < matrix.size(); i++)
		{
			double val = x0[i] - prevX[i];
			sum += val * val;
		}
		error = sqrt(sum);
		iter++;
	}
	return x0;
}
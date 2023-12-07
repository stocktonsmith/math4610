#include "linearSolverRoutines.hpp"

#include <iostream>
#include <format>
#include <cmath>

std::vector<double> jacobiIteration(const std::vector<std::vector<double>> matrix, const std::vector<double> rhs,
	std::vector<double> x0, double tol, int maxIter)
{
	std::vector<double> solutions(matrix.size());
	std::vector<double> residual(matrix.size());

	double error = 10 * tol;
	int iter = 0;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		double sum = rhs[i];
		for (size_t j = 0; j < matrix.size(); j++)
		{
			sum -= matrix[i][j] * x0[i];
		}
		residual[i] = sum;
	}

	while (error > tol && iter < maxIter)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			solutions[i] = x0[i] + residual[i] / matrix[i][i];
		}

		double sum = 0;
		for (size_t i = 0; i < matrix.size(); i++)
		{
			double val = solutions[i] - x0[i];
			sum += val * val;
		}
		error = sqrt(sum);

		for (size_t i = 0; i < matrix.size(); i++)
		{
			x0[i] = solutions[i];
		}

		for (size_t i = 0; i < matrix.size(); i++)
		{
			sum = rhs[i];
			for (size_t j = 0; j < matrix.size(); j++)
			{
				sum -= matrix[i][j] * x0[j];
			}
			residual[i] = sum;
		}
		iter++;
	}

	return solutions;
}
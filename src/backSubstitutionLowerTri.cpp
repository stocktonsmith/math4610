#include "linearSolverRoutines.hpp"

#include <iostream>
#include <format>

std::vector<double> backSubstitutionLowerTri(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
{
	std::vector<double> solutions(matrix.size());

	for (size_t xNum = 1; xNum <= matrix.size(); xNum++)
	{
		double constants = 0;
		for (size_t constantNum = 1; xNum > constantNum; constantNum++)
		{
			constants += (solutions[constantNum - 1] * matrix[xNum - 1][constantNum - 1]);
		}
		double result = (rhs[xNum - 1] - constants) / (matrix[xNum - 1][xNum - 1]);
		solutions[xNum - 1] = result;
	}

	return solutions;
}
#include "linearSolverRoutines.hpp"

#include <iostream>
#include <format>

std::vector<double> backSubstitutionUpperTri(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
{
	std::vector<double> solutions(matrix.size());

	for (size_t xNum = matrix.size(); xNum > 0; xNum--)
	{
		double constants = 0;
		for (size_t constantNum = matrix.size(); constantNum > xNum; constantNum--)
		{
			constants += (solutions[constantNum - 1] * matrix[xNum - 1][constantNum - 1]);
		}
		double result = (rhs[xNum - 1] - constants) / (matrix[xNum - 1][xNum - 1]);
		solutions[xNum - 1] = result;
	}

	return solutions;
}
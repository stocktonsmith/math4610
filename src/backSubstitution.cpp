#include "mathRoutines.hpp"

#include <iostream>
#include <format>

void backSubstitution(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
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

	for (size_t xNum = 0; xNum < matrix.size(); xNum++)
	{
		std::cout << "x" << xNum + 1 << " = " << solutions[xNum] <<
			"\t\tERROR: " << absError(1, solutions[xNum]) << std::endl;
	}
}
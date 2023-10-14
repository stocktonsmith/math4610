#include "mathRoutines.hpp"

#include <iostream>
#include <format>

void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			std::cout << std::format("{:>10.3}", matrix[i][j]);
		}
		std::cout << std::format("   |  {:>10.3}", rhs[i]) << std::endl;
	}
	std::cout << std::endl;
}
#include "mathRoutines.hpp"

std::vector<double> multiplySquareMatrixByOnes(const std::vector<std::vector<double>>& matrix)
{
	std::vector<double> rhsToReturn(matrix.size());
	for (size_t rowNum = 0; rowNum < matrix.size(); rowNum++)
	{
		double total = 0;
		for (size_t colNum = 0; colNum < matrix.size(); colNum++)
		{
			total += matrix[rowNum][colNum];
		}
		rhsToReturn[rowNum] = total;
	}
	return rhsToReturn;
}
#include "mathRoutines.hpp"

std::vector<double> multiplySquareMatrixByVec(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs)
{
	std::vector<double> rhsToReturn(matrix.size());
	for (size_t rowNum = 0; rowNum < matrix.size(); rowNum++)
	{
		double total = 0;
		for (size_t colNum = 0; colNum < matrix.size(); colNum++)
		{
			total += matrix[rowNum][colNum] * rhs[colNum];
		}
		rhsToReturn[rowNum] = total;
	}
	return rhsToReturn;
}

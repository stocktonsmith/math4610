#include "linearSolverRoutines.hpp"

void squareMatrixToUpperTri(std::vector<std::vector<double>>& matrix, std::vector<double>& rhs)
{
	for (size_t colIndex = 0; colIndex < matrix.size(); colIndex++)
	{
		double valOnDiag = matrix[colIndex][colIndex];
		for (size_t rowIndex = colIndex + 1; rowIndex < matrix.size(); rowIndex++)
		{
			double ratio = matrix[rowIndex][colIndex] / valOnDiag;
			for (size_t colToReduce = colIndex; colToReduce < matrix.size(); colToReduce++)
			{
				matrix[rowIndex][colToReduce] -= (ratio * matrix[colIndex][colToReduce]);
			}
			rhs[rowIndex] -= (ratio * rhs[colIndex]);
		}
	}
}
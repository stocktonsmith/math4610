#include "linearSolverRoutines.hpp"

std::vector<std::vector<std::vector<double>>> squareMatrixToLU(std::vector<std::vector<double>> matrixU)
{
	const int matrixSize = matrixU.size();
	std::vector<std::vector<std::vector<double>>> LU_container;
	std::vector<std::vector<double>> matrixL(matrixSize, std::vector<double>(matrixSize, 0));

	for (size_t colIndex = 0; colIndex < matrixU.size(); colIndex++)
	{
		double valOnDiag = matrixU[colIndex][colIndex];
		matrixL[colIndex][colIndex] = 1;
		for (size_t rowIndex = colIndex + 1; rowIndex < matrixU.size(); rowIndex++)
		{
			double ratio = matrixU[rowIndex][colIndex] / valOnDiag;
			matrixL[rowIndex][colIndex] = ratio;
			for (size_t colToReduce = colIndex; colToReduce < matrixU.size(); colToReduce++)
			{
				matrixU[rowIndex][colToReduce] -= (ratio * matrixU[colIndex][colToReduce]);
			}
		}
	}

	LU_container.push_back(matrixL);
	LU_container.push_back(matrixU);
	return LU_container;
}
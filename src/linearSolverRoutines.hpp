#pragma once

#include <vector>

// Linear Algebra Routines
void squareMatrixToUpperTri(std::vector<std::vector<double>>& matrix, std::vector<double>& rhs);
std::vector<std::vector<std::vector<double>>> squareMatrixToLU(std::vector<std::vector<double>> matrixU);
std::vector<double> backSubstitutionUpperTri(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
std::vector<double> backSubstitutionLowerTri(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);

// Appendix (Helper functions)
std::vector<double> multiplySquareMatrixByVec(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs);
void printMatrix(const std::vector<std::vector<double>>& matrix);
void printMatrix(const std::vector<double>& vector);
#pragma once

#include <vector>

// Linear Algebra Routines
void squareMatrixToUpperTri(std::vector<std::vector<double>>& matrix, std::vector<double>& rhs);
std::vector<std::vector<std::vector<double>>> squareMatrixToLU(std::vector<std::vector<double>> matrixU);
std::vector<double> backSubstitutionUpperTri(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
std::vector<double> backSubstitutionLowerTri(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
std::vector<double> jacobiIteration(const std::vector<std::vector<double>> matrix, const std::vector<double> rhs,
	std::vector<double> x0, double tol, int maxIter);
std::vector<double> gaussSeidel(const std::vector<std::vector<double>> matrix, const std::vector<double> rhs,
	std::vector<double> x0, double tol, int maxIter);

double powerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector, double tol, int maxIter);
double inversePowerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector,
	double mu, double tol, int maxIter);

// Appendix (Helper functions)
std::vector<double> multiplySquareMatrixByVec(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
std::vector<double> multiplyLeslieMatrixByVec(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs);
void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs);
void printMatrix(const std::vector<std::vector<double>>& matrix);
void printMatrix(const std::vector<double>& vector);
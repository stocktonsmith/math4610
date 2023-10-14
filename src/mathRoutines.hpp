#pragma once

#include <vector>

float smaceps();
double dmaceps();

double l2Norm(std::vector<double> vector);
double l1Norm(std::vector<double> vector);
double linfNorm(std::vector<double> vector);

std::vector<double> subtractTwoVectors(std::vector<double> vector1, std::vector<double> vector2);

double distancel2Norm(std::vector<double> vector1, std::vector<double> vector2);
double distancel1Norm(std::vector<double> vector1, std::vector<double> vector2);
double distancelinfNorm(std::vector<double> vector1, std::vector<double> vector2);

double myFunction(double x);
double myFunctionDeriv(double x);

double forwardDiffQuotient(double x, double h);
double backwardDiffQuotient(double x, double h);
double centralDiffQuotient(double x, double h);

double absError(double exact, double approx);
std::vector<double> linreg(std::vector<double> vector1, std::vector<double> vector2);

void squareMatrixToUpperTri(std::vector<std::vector<double>>& matrix, std::vector<double>& rhs);
void backSubstitution(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs);
std::vector<double> multiplySquareMatrixByOnes(const std::vector<std::vector<double>>& matrix);

void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs);
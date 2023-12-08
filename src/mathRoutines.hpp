#pragma once

#include <vector>

// Basic Routines
float smaceps();
double dmaceps();
double l2Norm(std::vector<double> vector);
double l1Norm(std::vector<double> vector);
double linfNorm(std::vector<double> vector);
double distancel2Norm(std::vector<double> vector1, std::vector<double> vector2);
double distancel1Norm(std::vector<double> vector1, std::vector<double> vector2);
double distancelinfNorm(std::vector<double> vector1, std::vector<double> vector2);
double forwardDiffQuotient(double x, double h);
double backwardDiffQuotient(double x, double h);
double centralDiffQuotient(double x, double h);
double absError(double exact, double approx);
std::vector<double> linreg(std::vector<double> vector1, std::vector<double> vector2);

double dotProduct(std::vector<double>& vec1, std::vector<double>& vec2);
void normalizeVector(std::vector<double>& vec);

// Appendix (Helper functions)
std::vector<double> subtractTwoVectors(std::vector<double> vector1, std::vector<double> vector2);
double myFunction(double x);
double myFunctionDeriv(double x);
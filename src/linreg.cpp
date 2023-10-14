#include "mathRoutines.hpp"

#include <iostream>

std::vector<double> linreg(std::vector<double> vector1, std::vector<double> vector2)
{
	double vecSize = static_cast<double>(vector1.size());
	double slope = 0.0;
	double yIntercept = 0.0;
	double vec1Sum = 0;
	double vec2Sum = 0;
	double vecProductSum = 0;
	double vec1SquaredSum = 0;

	for (int i = 0; i < vecSize; i++)
	{
		vec1Sum += vector1[i];
		vec2Sum += vector2[i];
		vecProductSum += (vector1[i] * vector2[i]);
		vec1SquaredSum += (vector1[i] * vector1[i]);
	}

	double numerator = (vecSize * vecProductSum) - (vec1Sum * vec2Sum);
	double denominator = (vecSize * vec1SquaredSum) - (vec1Sum * vec1Sum);
	slope = numerator / denominator;
	yIntercept = ((vec2Sum)-(slope * vec1Sum)) / (vecSize);

	std::vector<double> bestFitVector = { slope, yIntercept };

	return bestFitVector;
}
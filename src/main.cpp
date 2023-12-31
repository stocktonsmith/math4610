#include "mathRoutines.hpp"
#include "linearSolverRoutines.hpp"
#include "rootFindingRoutines.hpp"

#include <format>
#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>
#include <random>

void testSmaceps()
{
	float smac = smaceps();

	if (1 + smac != smac && 1 + (smac/2) == 1) { std::cout << "testSmaceps Test 1 passed" << std::endl; }
	else { std::cout << "testSmaceps Test 1 failed" << std::endl; }
}

void testDmaceps()
{
	double dmac = dmaceps();

	if (1 + dmac != dmac && 1 + (dmac / 2) == 1) { std::cout << "testDmaceps Test 1 passed" << std::endl; }
	else { std::cout << "testDmaceps Test 1 failed" << std::endl; }
}

void testL2Norm()
{
	std::vector<double> vector1 = { 2, 4.6, -3, 4};
	std::vector<double> vector2 = { 3.3, 0, 4.5, -6, -1 };

	if (absError(7.08237248, l2Norm(vector1)) < .0001) { std::cout << "testL2Norm Test 1 passed" << std::endl; }
	else { std::cout << "testL2Norm Test 1 failed" << std::endl; }
	if (absError(8.25469563, l2Norm(vector2)) < .0001) { std::cout << "testL2Norm Test 2 passed" << std::endl; }
	else { std::cout << "testL2Norm Test 2 failed" << std::endl; }
}

void testL1Norm()
{
	std::vector<double> vector1 = { 3, 6, 9 };
	std::vector<double> vector2 = { -4, 6.4, 2, 0, -7.25 };

	if (l1Norm(vector1) == 18) { std::cout << "testL1Norm Test 1 passed" << std::endl; }
	else { std::cout << "testL1Norm Test 1 failed" << std::endl; }
	if (l1Norm(vector2) == 19.65) { std::cout << "testL1Norm Test 2 passed" << std::endl; }
	else { std::cout << "testL1Norm Test 2 failed" << std::endl; }
}

void testLInfNorm()
{
	std::vector<double> vector1 = { 4, 6.5, 3, 1.5 };
	std::vector<double> vector2 = { -9, 7, 2, 8.4, -6, -1.7 };

	if (linfNorm(vector1) == 6.5) { std::cout << "testLInfNorm Test 1 passed" << std::endl; }
	else { std::cout << "testLInfNorm Test 1 failed" << std::endl; }
	if (linfNorm(vector2) == 9) { std::cout << "testLInfNorm Test 2 passed" << std::endl; }
	else { std::cout << "testLInfNorm Test 2 failed" << std::endl; }
}

void testSubtractTwoVectors()
{
	std::vector<double> vector1 = { 3, -5, 6 };
	std::vector<double> vector2 = { 1.5, -2.5, -5 };

	if (subtractTwoVectors(vector1, vector2)[0] == -1.5) { std::cout << "testSubtractTwoVectors Test 1 passed" << std::endl; }
	else { std::cout << "testSubtractTwoVectors Test 1 failed" << std::endl; }
	if (subtractTwoVectors(vector1, vector2)[1] == 2.5) { std::cout << "testSubtractTwoVectors Test 2 passed" << std::endl; }
	else { std::cout << "testSubtractTwoVectors Test 2 failed" << std::endl; }
	if (subtractTwoVectors(vector1, vector2)[2] == -11) { std::cout << "testSubtractTwoVectors Test 3 passed" << std::endl; }
	else { std::cout << "testSubtractTwoVectors Test 3 failed" << std::endl; }
}

void testDistanceL2Norm()
{
	std::vector<double> vector1 = { 8, 3, -5 };
	std::vector<double> vector2 = { 6, 0, -2 };
	std::vector<double> vector3 = { 3.7, -2, 4.15, 9 };
	std::vector<double> vector4 = { 1.4, 5.9, -8, 3.33 };

	if (absError(4.69041576, distancel2Norm(vector1, vector2)) < .0001) { std::cout << "testDistanceL2Norm Test 1 passed" << std::endl; }
	else { std::cout << "testDistanceL2Norm Test 1 failed" << std::endl; }
	if (absError(15.73122373, distancel2Norm(vector3, vector4)) < .0001) { std::cout << "testDistanceL2Norm Test 2 passed" << std::endl; }
	else { std::cout << "testDistanceL2Norm Test 2 failed" << std::endl; }
}

void testDistanceL1Norm()
{
	std::vector<double> vector1 = { 4.5, 3.7, 1.4 };
	std::vector<double> vector2 = { -2, -5, -7 };
	std::vector<double> vector3 = { -2.2, 5, 10, -6.6 };
	std::vector<double> vector4 = { 9, 14.5, .25, -1 };

	if (distancel1Norm(vector1, vector2) == 23.6) { std::cout << "testDistanceL1Norm Test 1 passed" << std::endl; }
	else { std::cout << "testDistanceL1Norm Test 1 failed" << std::endl; }
	if (distancel1Norm(vector3, vector4) == 36.05) { std::cout << "testDistanceL1Norm Test 2 passed" << std::endl; }
	else { std::cout << "testDistanceL1Norm Test 2 failed" << std::endl; }
}

void testDistanceLInfNorm()
{
	std::vector<double> vector1 = { 8, -4.4, 3 };
	std::vector<double> vector2 = { 2, 7, -2 };
	std::vector<double> vector3 = { 2.2, 3.3, -5.5, -6.6 };
	std::vector<double> vector4 = { 4, -3, 2, -1 };

	if (distancelinfNorm(vector1, vector2) == 11.4) { std::cout << "testDistanceLInfNorm Test 1 passed" << std::endl; }
	else { std::cout << "testDistanceLInfNorm Test 1 failed" << std::endl; }
	if (distancelinfNorm(vector3, vector4) == 7.5) { std::cout << "testDistanceLInfNorm Test 2 passed" << std::endl; }
	else { std::cout << "testDistanceLInfNorm Test 2 failed" << std::endl; }
}

void testLinreg()
{
	std::vector<double> vector1 = { 1, 2, 3, 4, 5, 6, 7 };
	std::vector<double> vector2 = { 1.5, 3.8, 6.7, 9.0, 11.2, 13.6, 16.0 };
	linreg(vector1, vector2);

	if (absError(2.4142857, linreg(vector1, vector2)[0]) < .0001) { std::cout << "testLinreg Test 1 passed" << std::endl; }
	else { std::cout << "testLinreg Test 1 failed" << std::endl; }
	if (absError(-0.828571, linreg(vector1, vector2)[1]) < .0001) { std::cout << "testLinreg Test 2 passed" << std::endl; }
	else { std::cout << "testLinreg Test 2 failed" << std::endl; }
}

void testMyFunction()
{
	if (myFunction(2) == 35) { std::cout << "testMyFunction Test 1 passed" << std::endl; }
	else { std::cout << "testMyFunction Test 1 failed"; }
	if (myFunction(-1) == -1) { std::cout << "testMyFunction Test 2 passed" << std::endl; }
	else { std::cout << "testMyFunction Test 2 failed"; }
	if (myFunction(1.5) == 17.125) { std::cout << "testMyFunction Test 3 passed" << std::endl; }
	else { std::cout << "testMyFunction Test 3 failed"; }
}

void testMyFunctionDeriv()
{
	if (myFunctionDeriv(2) == 45) { std::cout << "testMyFunctionDeriv Test 1 passed" << std::endl; }
	else { std::cout << "testMyFunctionDeriv Test 1 failed"; }
	if (myFunctionDeriv(-1) == 6) { std::cout << "testMyFunctionDeriv Test 2 passed" << std::endl; }
	else { std::cout << "testMyFunctionDeriv Test 2 failed"; }
	if (myFunctionDeriv(1.5) == 27.25) { std::cout << "testMyFunctionDeriv Test 3 passed" << std::endl; }
	else { std::cout << "testMyFunctionDeriv Test 3 failed"; }
}

void testForwardDiffQuotient()
{
	if (absError(47.03, forwardDiffQuotient(2, .1)) < .0001) { std::cout << "testForwardDiffQuotient Test 1 passed" << std::endl; }
	else { std::cout << "testForwardDiffQuotient Test 1 failed" << std::endl; }
	if (absError(49.12, forwardDiffQuotient(2, .2)) < .0001) { std::cout << "testForwardDiffQuotient Test 2 passed" << std::endl; }
	else { std::cout << "testForwardDiffQuotient Test 2 failed" << std::endl; }
}

void testBackwardDiffQuotient()
{
	if (absError(43.03, backwardDiffQuotient(2, .1)) < .0001) { std::cout << "testBackwardDiffQuotient Test 1 passed" << std::endl; }
	else { std::cout << "testBackwardDiffQuotient Test 1 failed" << std::endl; }
	if (absError(41.12, backwardDiffQuotient(2, .2)) < .0001) { std::cout << "testBackwardDiffQuotient Test 2 passed" << std::endl; }
	else { std::cout << "testBackwardDiffQuotient Test 2 failed" << std::endl; }
}

void testCentralDiffQuotient()
{
	if (absError(45.03, centralDiffQuotient(2, .1)) < .0001) { std::cout << "testCentralDiffQuotient Test 1 passed" << std::endl; }
	else { std::cout << "testCentralDiffQuotient Test 1 failed" << std::endl; }
	if (absError(45.12, centralDiffQuotient(2, .2)) < .0001) { std::cout << "testCentralDiffQuotient Test 2 passed" << std::endl; }
	else { std::cout << "testCentralDiffQuotient Test 2 failed" << std::endl; }
}


// LINEAR ALGEBRA ROUTINES:

void testGaussianLinearSolver()
{
	std::cout << "\n TESTING GAUSSIAN LINEAR SOLVER ON 5x5 MATRIX:" << std::endl;

	const int matrixSize = 5;
	std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
	std::vector<double> rhs;

	std::random_device randomDevice;
	std::default_random_engine engine(randomDevice());
	std::uniform_real_distribution<double> uniformDist(0, 1);

	for (size_t i = 0; i < matrix.size(); i++)
	{
		double total = 0;
		for (size_t j = 0; j < matrix.size(); j++)
		{
			matrix[i][j] = uniformDist(engine);
			total += matrix[i][j];
		}
		matrix[i][i] = total + 1;
		rhs.push_back(1);
	}
	std::cout << std::endl;

	rhs = multiplySquareMatrixByVec(matrix, rhs);

	printMatrix(matrix, rhs);
	squareMatrixToUpperTri(matrix, rhs);
	printMatrix(matrix, rhs);
	std::cout << std::endl;

	std::vector<double> solutions = backSubstitutionUpperTri(matrix, rhs);

	std::cout << "SOLUTIONS: " << std::endl;
	for (size_t soln = 0; soln < solutions.size(); soln++)
	{
		std::cout << "X" << (soln + 1) << " = " << solutions[soln] <<
			"          ERROR: " << absError(1, solutions[soln]) << std::endl;
	}
}

void testLULinearSolver()
{
	std::cout << "\n TESTING LINEAR LU SOLVER ON 5x5 MATRIX:" << std::endl;

	const int matrixSize = 5;
	std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
	std::vector<double> rhs;

	std::random_device randomDevice;
	std::default_random_engine engine(randomDevice());
	std::uniform_real_distribution<double> uniformDist(0, 1);

	for (size_t i = 0; i < matrix.size(); i++)
	{
		double total = 0;
		for (size_t j = 0; j < matrix.size(); j++)
		{
			matrix[i][j] = uniformDist(engine);
			total += matrix[i][j];
		}
		matrix[i][i] = total + 1;
		rhs.push_back(1);
	}
	std::cout << std::endl;

	rhs = multiplySquareMatrixByVec(matrix, rhs);

	printMatrix(matrix, rhs);
	std::vector<std::vector<std::vector<double>>> LU_container = squareMatrixToLU(matrix);
	printMatrix(LU_container[0], rhs);
	rhs = backSubstitutionLowerTri(LU_container[0], rhs);
	printMatrix(LU_container[1], rhs);

	std::vector<double> solutions = backSubstitutionUpperTri(matrix, rhs);
	solutions = backSubstitutionUpperTri(LU_container[1], rhs);
	std::cout << std::endl;

	std::cout << "SOLUTIONS: " << std::endl;
	for (size_t soln = 0; soln < solutions.size(); soln++)
	{
		std::cout << "X" << (soln + 1) << " = " << solutions[soln] <<
			"          ERROR: " << absError(1, solutions[soln]) << std::endl;
	}
}

void testFixedPointMethod()
{
	std::cout << "\nExpected guaranteed root: x = 2" << std::endl;
	fixedPointIteration(2.25, 1000, 1);
	std::cout << "Expected guaranteed root: x = 3" << std::endl;
	fixedPointIteration(3.4, 1000, 1);
}

void testBisectionMethod()
{
	std::cout << "\nExpected roots: x = 2 and x = 3" << std::endl;
	double root = bisectionMethod(0.8, 2.2, .000001, 100);
	std::cout << "ROOT 1 FROM BISECTION: " << root << std::endl;
	root = bisectionMethod(2.2, 4.3, .000001, 100);
	std::cout << "ROOT 2 FROM BISECTION: " << root << std::endl;
}

void testNewtonMethod()
{
	std::cout << "\nExpected roots: x = 2 and x = 3" << std::endl;
	double newtonRoot = newtonMethod(1.9, .000001, 100);
	std::cout << "NEWTON ROOT: " << newtonRoot << std::endl;
	newtonRoot = newtonMethod(5, .000001, 100);
	std::cout << "NEWTON ROOT: " << newtonRoot << std::endl;
}

void testSecantMethod()
{
	std::cout << "\nExpected roots: x = 2 and x = 3" << std::endl;
	double secantRoot = secantMethod(2.1, 2.75, .000001, 100);
	std::cout << "SECANT ROOT: " << secantRoot << std::endl;
	secantRoot = secantMethod(3.5, 3.8, .000001, 100);
	std::cout << "SECANT ROOT: " << secantRoot << std::endl;
}

void testHybridMethod()
{
	std::cout << "\nExpected roots: x = 2 and x = 3" << std::endl;

	double hybridRoot = hybridMethod(1.34, 2.8, .000001, 100);
	std::cout << "HYBRID ROOT: " << hybridRoot << std::endl;
	hybridRoot = hybridMethod(2.6, 78, .000001, 100);
	std::cout << "HYBRID ROOT: " << hybridRoot << std::endl;
}

int main()
{
	/*
	testSmaceps();
	testDmaceps();
	testL2Norm();
	testL1Norm();
	testLInfNorm();
	testSubtractTwoVectors();
	testDistanceL2Norm();
	testDistanceL1Norm();
	testDistanceLInfNorm();
	testLinreg();
	testMyFunction();
	testMyFunctionDeriv();
	testForwardDiffQuotient();
	testBackwardDiffQuotient();
	testCentralDiffQuotient();
	*/

	//testGaussianLinearSolver();
	//testLULinearSolver();

	testFixedPointMethod();
	testBisectionMethod();
	testNewtonMethod();
	testSecantMethod();
	testHybridMethod();

	return 0;
}

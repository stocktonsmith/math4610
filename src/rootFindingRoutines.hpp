#pragma once

#include <vector>

// Root Finding Routines
void fixedPointIteration(double x0, int maxIter, double eps);
double bisectionMethod(double a, double b, double tol, int maxIter);
double newtonMethod(double x, double tol, int maxIter);
double secantMethod(double x0, double x1, double tol, int maxIter);
double hybridMethod(double a, double b, double tol, int maxIter);
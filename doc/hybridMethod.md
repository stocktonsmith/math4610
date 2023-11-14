**Routine Name**: hybridMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the Hybrid root-finding method, which is one way to compute a root of a pre-determined function of x. This is a combination of [bisectionMethod()](bisectionMethod.md) and [secantMethod()](secantMethod.md). The desired function to be solved can be changed by altering the [myFunction()](myFunction.md) function.  
**Input**: The function requires four parameters: a `double` representing "a" (the left interval endpoint), a `double` representing "b" (the right interval endpoint), a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting.  
To guarantee that the root is accurately computed, be sure that fa * fb <= 0 for your chosen "a" and "b" values.  
**Output**: The routine returns one root of the function in the form of a `double`.  A message will be printed if the root isn't guaranteed to be accurate.  
**Usage Example**:  
*Input*:  

    double hybridRoot = hybridMethod(1.34, 2.8, .000001, 100);
    std::cout << "HYBRID ROOT: " << hybridRoot << std::endl;
    hybridRoot = hybridMethod(2.6, 78, .000001, 100);
    std::cout << "HYBRID ROOT: " << hybridRoot << std::endl;

*Output*:  

    HYBRID ROOT: 2
    HYBRID ROOT: 3

In this test case, [myFunction()](myFunction.md) is implemented to represent f(x) = x^2 - 5x + 6. This shows that the hybridMethod() function is capable of accurately determining both roots of the function.

**Implementation**: The following is the code for hybridMethod():  

    double hybridMethod(double a, double b, double tol, int maxIter) {
        double fa = myFunction(a);
        double fb = myFunction(b);
        double error = 10 * tol;
        int iter = 0;
        double c = 0;

        if (fa == 0) {
            return fa;
        }
        else if (fb == 0) {
            return fb;
        }
        else if (fa * fb > 0) {
            std::cout << "f(a) * f(b) > 0. This interval can't guarantee a root." << std::endl;
        }

        while (error > tol && iter < maxIter) {
            double x0 = (a + b) / 2;
            double fx0 = myFunction(x0);
            double x1 = x0 - (fx0) / myFunctionDeriv(x0);
            double fx1 = myFunction(x1);

            double nextX1 = x1 - fx1 * ((x1 - x0) / (fx1 - fx0));
            if (nextX1 >= a && nextX1 <= b) {
                c = x0;
                double fc = myFunction(c);
                for (int i = 0; i < 4; i++) {
                    if (fa * fc < 0) {
                        b = c;
                        fb = fc;
                    }
                    else {
                        a = c;
                        fa = fc;
                    }
                    c = (a + b) / 2;
                }
            }
            else {
                return secantMethod(x0, x1, tol, maxIter);
            }
            iter++;
        }

        return c;
    }

**Last Modified**: November/2023
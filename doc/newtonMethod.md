**Routine Name**: newtonMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the Newton root-finding method, which is one way to compute a root of a pre-determined function of x. The desired function to be solved can be changed by altering the [myFunction()](myFunction.md) function, and the function's derivative can be changed by altering the [myFunctionDeriv()](myFunctionDeriv.md) function.  
**Input**: The function requires three parameters: a `double` representing the initial guess, a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting.  
**Output**: The routine returns one root of the function in the form of a `double`.  A message will be printed if the root isn't guaranteed to be accurate.  
**Usage Example**:  
*Input*:  

    double newtonRoot = newtonMethod(1.9, .000001, 100);
    std::cout << "NEWTON ROOT 1: " << newtonRoot << std::endl;
    newtonRoot = newtonMethod(5, .000001, 100);
    std::cout << "NEWTON ROOT 2: " << newtonRoot << std::endl;  

*Output*:  

    NEWTON ROOT 1: 2
    NEWTON ROOT 2: 3

In this test case, [myFunction()](myFunction.md) is implemented to represent f(x) = x^2 - 5x + 6, and [myFunctionDeriv()](myFunctionDeriv.md) is implemented to represent f'(x) = 2x - 5. This shows that the newtonMethod() function is capable of accurately determining both roots of the function.

**Implementation**: The following is the code for newtonMethod():  

    double newtonMethod(double x, double tol, int maxIter) {
        int iter = 0;

        while (iter < maxIter) {
            double fx = myFunction(x);
            double fPrimeX = myFunctionDeriv(x);
            double nextX = x - (fx / fPrimeX);
            if (std::abs(nextX - x) < tol) {
                return x;
            }
            x = nextX;
            iter++;
        }
        std::cout << "Max iterations reached. Root accuracy is not guaranteed." << std::endl;
        return x;
    }

**Last Modified**: November/2023
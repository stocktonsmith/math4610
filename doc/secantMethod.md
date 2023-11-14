**Routine Name**: secantMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the Secant root-finding method, which is one way to compute a root of a pre-determined function of x. The desired function to be solved can be changed by altering the [myFunction()](myFunction.md) function.  
**Input**: The function requires four parameters: a `double` representing the initial value x0, a `double` representing the initial value x1, a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting.  
**Output**: The routine returns one root of the function in the form of a `double`.  A message will be printed if the root isn't guaranteed to be accurate.  
**Usage Example**:  
*Input*:  

    double secantRoot = secantMethod(-1, 1, .000001, 100);
    std::cout << "SECANT ROOT 1: " << secantRoot << std::endl;
    secantRoot = secantMethod(3.5, 3.8, .000001, 100);
    std::cout << "SECANT ROOT 2: " << secantRoot << std::endl;

*Output*:  

    SECANT ROOT 1: 2
    SECANT ROOT 2: 3

In this test case, [myFunction()](myFunction.md) is implemented to represent f(x) = x^2 - 5x + 6. This shows that the secantMethod() function is capable of accurately determining both roots of the function.

**Implementation**: The following is the code for secantMethod():  

    double secantMethod(double x0, double x1, double tol, int maxIter) {
        int iter = 0;
        while (iter < maxIter) {
            double fx0 = myFunction(x0);
            double fx1 = myFunction(x1);
            double nextX1 = x1 - fx1 * ((x1 - x0) / (fx1 - fx0));

            if (std::abs(nextX1 - x1) < tol) {
                return x1;
            }

            x0 = x1;
            x1 = nextX1;
            iter++;
        }
        std::cout << "Max iterations reached. Root accuracy is not guaranteed." << std::endl;
        return x1;
    }

**Last Modified**: November/2023
**Routine Name**: bisectionMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the Bisection root-finding method, which is one way to compute a root of a pre-determined function of x. The desired function to be solved can be changed by altering the [myFunction()](myFunction.md) function.  
**Input**: The function requires four parameters: a `double` representing "a" (the left interval endpoint), a `double` representing "b" (the right interval endpoint), a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting.  
To guarantee that the root is accurately computed, be sure that fa * fb <= 0 for your chosen "a" and "b" values.  
**Output**: The routine returns one root of the function in the form of a `double`.  A message will be printed if the root isn't guaranteed to be accurate.  
**Usage Example**:  
*Input*:  

    double root = bisectionMethod(0.8, 2.2, .000001, 100);
    std::cout << "ROOT 1 FROM BISECTION: " << root << std::endl;
    root = bisectionMethod(2.2, 4, .000001, 100);
    std::cout << "ROOT 2 FROM BISECTION: " << root << std::endl;  

*Output*:  

    ROOT 1 FROM BISECTION: 2
    ROOT 2 FROM BISECTION: 3

In this test case, [myFunction()](myFunction.md) is implemented to represent f(x) = x^2 - 5x + 6. This shows that the bisectionMethod() function is capable of accurately determining both roots of the function.

**Implementation**: The following is the code for bisectionMethod():  

    double bisectionMethod(double a, double b, double tol, int maxIter) {
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
            c = (a + b) / 2;
            double fc = myFunction(c);
            if (fa * fc <= 0) {
                b = c;
                fb = fc;
            }
            else {
                a = c;
                fa = fc;
            }

            error = b - a;
            iter++;
        }

        return c;
    }

**Last Modified**: November/2023
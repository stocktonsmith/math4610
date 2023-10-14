**Routine Name**: myFunctionDeriv()  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function simply returns an exact value of a known derivative function evaluated at a point.  
**Input**: A double value, representing the point at which to evaluate the derivative function, is taken as input.  
**Output**: A double value, representing the exact value of a derivative function evaluated at a point, is returned.  
**Usage Example**:  
*Input*:  

    std::cout << "MYFUNCTION DERIV: " << myFunctionDeriv(2) << std::endl;

*Output*:  

    MYFUNCTION DERIV: 45

In this test case, we have defined our derivative function to be 9x^2 + 4x + 1, which is the derivative of the function implemented in myFunction(). The code accurately determines that, for an input of x = 2, the exact value of the derivative is 45.

**Implementation**: The following is the code for myFunctionDeriv():  

    double myFunctionDeriv(double x)
    {
        return (9 * x * x) + (4 * x) + 1;
    }

**Last Modified**: October/2023
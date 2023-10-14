**Routine Name**: centralDiffQuotient  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function approximates the derivative of a function using the central difference quotient. Note that this uses the myFunction() function from the appendix.  
**Input**: The user provides x, a double, which is the point for the approximation to be evaluated at. The user also provides h, another double, which acts as the increment for the difference quotient.  
**Output**:  The routine returns a double representing the central difference quotient approximation of the derivative.  
**Usage Example**:  
*Input*:  

    std::cout << "CENTRAL DIFF QUOTIENT: " << centralDiffQuotient(2, .1) << std::endl;

*Output*:  

    CENTRAL DIFF QUOTIENT: 45.03

This test case demonstrates that, for the function described in myFunction() above, the derivative approximation using the central difference quotient (with x = 2 and h = 0.1) is 45.03. Compare this with the exact value of the derivative determined using myFunctionDeriv(), which is 45.

**Implementation**: The following is the code for centralDiffQuotient():  

    double centralDiffQuotient(double x, double h)
    {
        return (myFunction(x + h) - myFunction(x - h)) / (2 * h);
    }

**Last Modified**: October/2023
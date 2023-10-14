**Routine Name**: forwardDiffQuotient  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function approximates the derivative of a function using the forward difference quotient. Note that this uses the myFunction() function from the appendix.  
**Input**: The user provides x, a double, which is the point for the approximation to be evaluated at. The user also provides h, another double, which acts as the increment for the difference quotient.  
**Output**:  The routine returns a double representing the forward difference quotient approximation of the derivative.  
**Usage Example**: 
*Input*:  

    std::cout << "FORWARD DIFF QUOTIENT: " << forwardDiffQuotient(2, .1) << std::endl;

*Output*:  

    FORWARD DIFF QUOTIENT: 47.03

This test case demonstrates that, for the function described in myFunction() above, the derivative approximation using the forward difference quotient (with x = 2 and h = 0.1) is 47.03. Compare this with the exact value of the derivative determined using myFunctionDeriv(), which is 45.

**Implementation**: The following is the code for forwardDiffQuotient():  

    double forwardDiffQuotient(double x, double h)
    {
        return (myFunction(x + h) - myFunction(x)) / h;
    }

**Last Modified**: October/2023
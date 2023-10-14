**Routine Name**: absError  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes in two values as input and computes the absolute error between them.  
**Input**: The user provides two double values to the function: the first represents the exact value of a function at a point, and the second represents an approximation of the same function.  
**Output**: The routine returns a double representing the absolute error between the exact value and the approximation.  
**Usage Example**:  
*Input*:  

    std::cout << absError(-3.5, -3.50047) << std::endl;

*Output*:  

    0.00047

This shows that the absolute error between -3.5 and -3.50047 is 0.00047.

**Implementation**: The following is the code for absError():  

    double absError(double exact, double approx)
    {
        return abs(exact - approx);
    }

**Last Modified**: October/2023
**Routine Name**: myFunction  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function simply returns an exact value of a known function evaluated at a point.  
**Input**: A double value, representing the point at which to evaluate the function, is taken as input.  
**Output**: A double value, representing the exact value of a function evaluated at a point, is returned.  
**Usage Example**:  
*Input*:  

    std::cout << "MYFUNCTION: " << myFunction(2) << std::endl;

*Output*:  

    MYFUNCTION: 35

In this test case, we have defined our function to be 3x^3 + 2x^2 + x + 1. The code accurately determines that, for an input of x = 2, the output is 35.

**Implementation**: The following is the code for myFunction():  

    double myFunction(double x)
    {
        return (3 * x * x * x) + (2 * x * x) + x + 1;
    }

**Last Modified**: October/2023
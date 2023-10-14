**Routine Name**: dmaceps  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function allows a user to determine the machine epsilon value for their machine using double precision.  
**Input**: No inputs are needed in this case.  
**Output**: This routine prints the smallest double-precision value that this machine can use without experiencing round-off error problems.  
**Usage Example**:  
*Input*:  

    std::cout << dmaceps() std::endl;

*Output*:  

    2.22045e-16

This would imply that 2.22045e-16 is the machine's double-precision machine epsilon value.

**Implementation**: The following is the code for dmaceps():

    double dmaceps()
    {
        double maceps = 0.5;
        while (1 + (maceps / 2) != 1)
        {
            maceps = maceps / 2;
        }
        return maceps;
    }

**Last Modified**: October/2023
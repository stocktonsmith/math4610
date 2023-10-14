**Routine Name**: smaceps  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function allows a user to determine the machine epsilon value for their machine using single precision.  
**Input**: No inputs are needed in this case.  
**Output**: This routine returns the smallest single-precision value that this machine can use without experiencing round-off error problems.  
**Usage Example**:   
*Input*:  

    std::cout << smaceps() << std::endl; 

*Output*:  

    1.19209e-07

This would imply that 1.19209e-07 is the machine's single-precision machine epsilon value.

**Implementation**: The following is the code for smaceps():

    float smaceps()
    {
        float maceps = 0.5f;
        while (1 + (maceps / 2) != 1)
        {
            maceps = maceps / 2;
        }
        return maceps;
    }

**Last Modified**: October/2023
**Routine Name**: linfNorm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes a single vector as input and computes its linf-norm.  
**Input**: A `std::vector<double>` is given as the input vector.  
**Output**: The routine returns a double representing the vector's linf-norm.  
**Usage Example**:  
*Input*:  

    std::vector<double> myVector = {-2, 6.25, -7, 4};  
    std::cout << linfNorm(myVector) << std::endl;  

*Output*: 

    7

This shows that 7 is the linf-norm of the vector {-2, 6.25, -7, 4}.

**Implementation**: The following is the code for linfNorm():  

    double linfNorm(std::vector<double> vector)
    {
        double norm = 0.0f;
        for (const auto& element : vector)
        {
            if (abs(element) > norm)
            {
                norm = fabs(element);
            }
        }
        return norm;
    }

**Last Modified**: October/2023
**Routine Name**: l2Norm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes a single vector as input and computes its l2-norm (i.e. Euclidean norm).  
**Input**: A `std::vector<double>` is given as the input vector.  
**Output**: The routine returns a double representing the vector's l2-norm.  
**Usage Example**:  
*Input*:  

    std::vector<double> myVector = {-2.5, 3, 5};  
    std::cout << l2Norm(myVector) << std::endl;  

*Output*:  

    6.34429

This shows that 6.34429 is the l2-norm of the vector {-2.5, 3, 5}.

**Implementation**: The following is the code for l2Norm():  

    double l2Norm(std::vector<double> vector)
    {
        double norm = 0.0;
        for (const auto& element : vector)
        {
            norm += element * element;
        }
        return sqrt(norm);
    }

**Last Modified**: October/2023
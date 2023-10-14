**Routine Name**: l1Norm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes a single vector as input and computes its l1-norm.  
**Input**: A `std::vector<double>` is given as the input vector.  
**Output**: The routine returns a double representing the vector's l1-norm.  
**Usage Example**:  
*Input*:  

    std::vector<double> myVector = {4, -1.5, 0, 3};  
    std::cout << l1Norm(myVector) << std::endl;  

*Output*:  

    8.5

This shows that 8.5 is the l1-norm of the vector {4, -1.5, 0, 3}.

**Implementation**: The following is the code for l1Norm():  

    double l1Norm(std::vector<double> vector)
    {
        double norm = 0.0f;
        for (const auto& element : vector)
        {
            norm += abs(element);
        }
        return norm;
    }

**Last Modified**: October/2023
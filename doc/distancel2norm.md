**Routine Norm**: distancel2Norm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes two vectors as input and returns the l2-norm (i.e. Euclidean norm) of the distance between them. Note that this uses the subtractTwoVectors() function from the appendix.  
**Input**: Two vectors are taken as input, each being of type `std::vector<double>`.  
**Output**: The routine returns a double representing the l2-norm of the distance between the two vectors.  
**Usage Example**:  
*Input*:  
        
    std::vector<double> myVector1 = {-2, 4, 6.5};  
    std::vector<double> myVector2 = {-1, 1, 3};  
    std::cout << distancel2Norm(myVector1, myVector2) << std::endl;  

*Output*:  

    4.71699

This demonstrates that the l2-norm of the distance between the 2 vectors is 4.71699.

**Implementation**: The following is the code for distancel2Norm():  

    double distancel2Norm(std::vector<double> vector1, std::vector<double> vector2)
    {
        return l2Norm(subtractTwoVectors(vector1, vector2));
    }

**Last Modified**: October/2023